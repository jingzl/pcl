#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int  main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ> cloud;   // Fill in the cloud data  
	cloud.width = 5;
	cloud.height = 1;
	cloud.is_dense = false;
	cloud.points.resize(cloud.width * cloud.height);
	for (std::size_t i = 0; i < cloud.points.size(); ++i)
	{
		cloud.points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
		cloud.points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
		cloud.points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);
	}
	pcl::io::savePCDFileASCII("test_pcd.pcd", cloud);
	std::cerr << "Saved " << cloud.points.size() << " data points to test_pcd.pcd." << std::endl;
	for (std::size_t i = 0; i < cloud.points.size(); ++i)
		std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl;
	return (0);
}



/*
用于lib文件分离debug/release版本的代码
#include <iostream>
#include <string>
#include <fstream> 
#include <iostream>
using namespace std;

int main()
{
	ifstream txtfile;//打开读取的文件
	ofstream txt01;//保存的文件
	ofstream txt02;//保存的文件
	string temp;
	int index = 0;//用于判断奇偶

	txtfile.open("pcl0.txt", ios::in);

	while (!txtfile.eof())      // 若未到文件结束一直循环
	{

		getline(txtfile, temp);//一行一行读取
		if (index % 2 == 0)//判断除以2的余数，即为奇偶的判断
		{
			txt01.open("pcl1.txt", ios::app);
			txt01 << temp;
			txt01 << endl;
			txt01.close();
		}
		else
		{
			txt02.open("pcl2.txt", ios::app);
			txt02 << temp;
			txt02 << endl;
			txt02.close();
		}
		index++;
	}
	txtfile.close();  //关闭文件
	txtfile.close();
	txt01.close();
	txt02.close();

	return 0;
}
*/