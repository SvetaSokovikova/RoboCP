#pragma once
#include "KinectViewer.h"


KinectViewer::KinectViewer (XMLConfig * x)
{
}

KinectViewer::~KinectViewer ()
{
	delete viewer;
}

void KinectViewer::Start ()
{ // Adding some objects to viewer, then we will only update these objects
	
  viewer = new pcl::visualization::PCLVisualizer ("Downsampled point cloud");

  boost::shared_ptr<KinectData> kData (new KinectData);
  kData->Time = time (NULL);
  viewer->addPointCloud (kData->Cloud, "cloud"); // Adding point cloud to viewer
  char buf[50]; 
  sprintf (buf, "Cloud time: %s", ctime(&kData->Time) );
  viewer->addText (buf, 5, 20, 10, 1, 1, 1, "CloudTime"); // Adding text line to viewer
  kData.reset();

  
  // Adding multiple text lines to viewer (Send data)
  
  viewer->addText ("Send:", 20, 305, 14, 1, 1, 1, "SendHead");
  viewer->addText ("Acceleration x:", 5, 290, 10, 1, 1, 1, "AccelerationX");
  viewer->addText ("Acceleration y:", 5, 278, 10, 1, 1, 1, "AccelerationY");
  viewer->addText ("Acceleration z:", 5, 268, 10, 1, 1, 1, "AccelerationZ");

  viewer->addText ("Top sonic:", 5, 248, 10, 1, 1, 1, "TopSonic");
  viewer->addText ("Left sonic:", 5, 238, 10, 1, 1, 1, "LeftSonic");
  viewer->addText ("Right sonic:", 5, 224, 10, 1, 1, 1, "RightSonic");
  viewer->addText ("Front sonic:", 5, 214, 10, 1, 1, 1, "FrontSonic");
  viewer->addText ("Back sonic:", 5, 202, 10, 1, 1, 1, "BackSonic");

  viewer->addText ("Alt barometer:", 5, 186, 10, 1, 1, 1, "AltBarometer");
  viewer->addText ("Alt sonic:", 5, 174, 10, 1, 1, 1, "AltSonic");
  viewer->addText ("Pitch:", 5, 162, 10, 1, 1, 1, "Pitch");
  viewer->addText ("Roll:", 5, 150, 10, 1, 1, 1, "Roll");
  viewer->addText ("Yaw:", 5, 138, 10, 1, 1, 1, "Yaw");

  viewer->addText ("Time:", 5, 122, 10, 1, 1, 1, "SendTime");
  
  // main loop
  while (!viewer->wasStopped() ) {
	viewer->spinOnce(100);
	Sleep (100);
  }

}