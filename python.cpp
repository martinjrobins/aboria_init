/*
 * Python.cpp
 *
 *  Created on: 7 Sep 2014
 *      Author: mrobins
 */


#include "Python.h"
#include "init.cpp"


BOOST_PYTHON_MODULE(init) {

	VTK_PYTHON_CONVERSION(vtkUnstructuredGrid);

	Vect3_from_python_list<double>();
	to_python_converter<
		Vect3d,
		Vect3_to_python<double> >();

	/*
	 * Particles
	 */
	class_<particles_type,typename std::shared_ptr<particles_type> >("Particles")
	        .def(boost::python::vector_indexing_suite<particles_type>())
	        .def("get_grid",&particles_type::get_grid)
	        .def("copy_from_vtk_grid",&particles_type::copy_from_vtk_grid)
	    ;

    #define ADD_PROPERTY(name) \
		.add_property("name", \
					make_function(&particles_type::value_type::template get<name>, \
									return_value_policy<copy_non_const_reference>()), \
					&particles_type::value_type::template set<name>)


	class_<particles_type::value_type, std::shared_ptr<particles_type::value_type> >("Particle",init<>())
		ADD_PROPERTY(id)
		ADD_PROPERTY(position)
		ADD_PROPERTY(alive)
		;
}
