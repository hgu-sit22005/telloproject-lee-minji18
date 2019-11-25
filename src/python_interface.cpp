#include <boost/python.hpp>

#include "TelloPro.h"
#include "takeoff.h"
#include "land.h"
#include "up.h"
#include "Flip.h"
#include "down.h"
#include "left.h"
#include "right.h"
#include "forward.h"
#include "back.h"
#include "cw.h"
#include "ccw.h"

TelloPro* get_instance(boost::python::str _inst, int _value)
{
	std::string instance = boost::python::extract<std::string>(_inst);

	if(instance == "takeoff")
	   return new Takeoff;
	else if(instance == "land")
		return new Land;
	else if (instance == "up")
		return new up(_value);
	else if (instance == "down")
		return new down(_value);
	else if (instance == "left")
		return new left(_value);
	else if (instance == "forward")
		return new forward(_value);
	else if (instance == "back")
		return new back(_value);
	else if (instance == "right")
		return new right(_value);
	else if (instance == "ccw")
		return new ccw(_value);
	else if (instance == "cw")
		return new cw(_value);
	else if (instance == "Flip")
		return new Flip(_value);
	else
		return nullptr;
}

BOOST_PYTHON_MODULE(TelloPro)
{
	def("get_instance", get_instance,
			      boost::python::return_value_policy<boost::python::manage_new_object>());
	
	boost::python::class_<TelloPro>("TelloPro")
		.def("get_command", &TelloPro::get_command)
		.def("get_delay", &TelloPro::get_delay);
}

