#include "jr_hector_map_server/jr_hector_map_server.hpp"

jr_hector_map_server::jr_hector_map_server( ros::NodeHandle &_nh, ros::NodeHandle &_nh_priv ) :
	nh( _nh ),
        nh_priv( _nh_priv )
{
	ROS_INFO("Initializing the hector map server.");
}

bool jr_hector_map_server::start()
{
	if(!map_server)
		map_server = nh.advertiseService("/map", &jr_hector_map_server::get_map, this);
	if( !map_sub )
                map_sub = nh.subscribe( "map", 1, &jr_hector_map_server::MapCB, this );
	
	ROS_INFO("...Done!");
	return true;
}

bool jr_hector_map_server::get_map(nav_msgs::GetMap::Request &request, nav_msgs::GetMap::Response &response)
{
	if(!current_map)
		return false;
	response.map = *current_map;
	return true;
}

void jr_hector_map_server::MapCB( const nav_msgs::OccupancyGridPtr &msg )
{
	current_map = msg;
}
