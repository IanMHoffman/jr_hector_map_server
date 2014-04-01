#ifndef _JR_HECTOR_MAP_SERVER_
#define _JR_HECTOR_MAP_SERVER_

#include <ros/ros.h>
#include <nav_msgs/GetMap.h>
#include <nav_msgs/OccupancyGrid.h>

class jr_hector_map_server
{
public:
	jr_hector_map_server( ros::NodeHandle &_nh, ros::NodeHandle &_nh_priv );
	void MapCB( const nav_msgs::OccupancyGridPtr &msg );    // get the map from hector
	bool get_map(nav_msgs::GetMap::Request &request, nav_msgs::GetMap::Response &response);
	bool start();

private:
	ros::ServiceServer map_server;	// service call for the map
	ros::Subscriber map_sub;	// subscription to hector's map

	nav_msgs::OccupancyGridPtr current_map;
	
	ros::NodeHandle nh;
	ros::NodeHandle nh_priv;
};

#endif
