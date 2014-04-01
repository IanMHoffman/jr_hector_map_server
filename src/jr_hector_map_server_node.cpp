#include <jr_hector_map_server/jr_hector_map_server.hpp>

int main( int argc, char *argv[] )
{
	ros::NodeHandle *nh = NULL;
	ros::NodeHandle *nh_priv = NULL;
	jr_hector_map_server *map_server = NULL;

	ros::init( argc, argv, "jr_hector_map_server_node" );

	nh = new ros::NodeHandle( );
	if( !nh )
	{
		ROS_FATAL( "Failed to initialize NodeHandle" );
		ros::shutdown( );
		return -1;
	}
	nh_priv = new ros::NodeHandle( "~" );
	if( !nh_priv )
	{
		ROS_FATAL( "Failed to initialize private NodeHandle" );
		delete nh;
		ros::shutdown( );
		return -2;
	}
	map_server = new jr_hector_map_server( *nh, *nh_priv );
	if( !map_server )
	{
		ROS_FATAL( "Failed to initialize driver" );
		delete nh_priv;
		delete nh;
		ros::shutdown( );
		return -3;
	}
	if( !map_server->start( ) )
		ROS_ERROR( "Failed to start the driver" );

	ros::spin( );

	delete map_server;
	delete nh_priv;
	delete nh;

	return 0;
}
