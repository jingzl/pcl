/*
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>

using pcl::PointCloud;
using pcl::PointXYZ;

int
main(int, char**)
{
	srand(unsigned(time(0)));

	PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);

	cloud->points.resize(5);
	for (std::size_t i = 0; i < cloud->size(); ++i)
	{
		(*cloud)[i].x = float(i);
		(*cloud)[i].y = float(i / 2);
		(*cloud)[i].z = 0.0f;
	}

	// Start the visualizer
	pcl::visualization::PCLVisualizer p("test_shapes");
	p.setBackgroundColor(1, 1, 1);
	p.addCoordinateSystem(1.0, "first");

	//p.addPolygon (cloud, "polygon");
	p.addPolygon<PointXYZ>(cloud, 1.0, 0.0, 0.0, "polygon", 0);
	p.setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 10, "polygon");

	p.addLine<PointXYZ, PointXYZ>((*cloud)[0], (*cloud)[1], 0.0, 1.0, 0.0);
	p.setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 50, "line");

	p.addSphere<PointXYZ>((*cloud)[0], 1, 0.0, 1.0, 0.0);
	p.setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 5, "sphere");
	//  p.removePolygon ("poly");

	p.addText("text", 200, 200, 1.0, 0, 0, "text");

	p.addText3D("text3D", (*cloud)[0], 1.0, 1.0, 0.0, 0.0);
	p.spin();
	p.removeCoordinateSystem("first", 0);
	p.spin();
	p.addCoordinateSystem(1.0, 5, 3, 1, "second");
	p.spin();
	p.removeCoordinateSystem("second", 0);
	p.spin();
}
*/

#include<pcl/visualization/cloud_viewer.h>
#include<iostream>//标准C++库中的输入输出类相关头文件。
#include<pcl/io/io.h>
#include<pcl/io/pcd_io.h>//pcd 读写类相关的头文件。
#include<pcl/io/ply_io.h>
#include<pcl/point_types.h> //PCL中支持的点类型头文件。


using namespace std;
using namespace pcl;


void viewerOneOff(visualization::PCLVisualizer& viewer) {
	viewer.setBackgroundColor(0, 0, 0);   //设置背景颜色为黑色
}

int main() {

	PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);

	char strfilepath[256] = "rabbit.pcd";
	if (-1 == io::loadPCDFile(strfilepath, *cloud)) {
		cout << "error input!" << endl;
		return -1;
	}

	cout << cloud->points.size() << endl;
	visualization::CloudViewer viewer("Cloud Viewer: Rabbit");     //创建viewer对象

	viewer.showCloud(cloud);
	viewer.runOnVisualizationThreadOnce(viewerOneOff);
	system("pause");
	return 0;
}


/*
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
*/


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