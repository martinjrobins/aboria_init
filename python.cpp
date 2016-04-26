/*
 * Python.cpp
 *
 *  Created on: 7 Sep 2014
 *      Author: mrobins
 */


#include "python.hpp"
#include "init.hpp"

template<typename T, typename VT>
const typename T::value_type & get_const(const VT & arg) {
    return arg.template get<T>();
}

template<typename T, typename VT>
typename T::value_type & get_non_const(VT & arg) {
    return arg.template get<T>();
}

template<typename T, typename VT>
void set_data(VT & arg, const typename T::value_type & data) {
    arg.template set<T>(data);
}

BOOST_PYTHON_MODULE(init) {

	VTK_PYTHON_CONVERSION(vtkUnstructuredGrid);

	Vect3_from_python_list<double>();
	Vect3_from_python_list<bool>();
	to_python_converter<
		Vect3d,
		Vect3_to_python<double> >();

    def("timestep", timestep);

	/*
	 * Particles
	 */
	class_<particles_type,typename std::shared_ptr<particles_type> >("Particles")
	        .def(boost::python::vector_indexing_suite<particles_type>())
	        .def("init_neighbour_search",&particles_type::init_neighbour_search)
	        .def("get_grid",&particles_type::get_grid)
	        .def("copy_from_vtk_grid",&particles_type::copy_from_vtk_grid)
            ;
    

    #define ADD_PROPERTY(name_string, name) \
		.add_property(name_string, \
					make_function(&get_non_const<name,particles_type::value_type>, \
									return_value_policy<copy_non_const_reference>()), \
					&set_data<name,particles_type::value_type>)


	class_<particles_type::value_type, std::shared_ptr<particles_type::value_type> >("Particle",init<>())
		ADD_PROPERTY("id",id)
		ADD_PROPERTY("position",position)
		ADD_PROPERTY("alive",alive)
		ADD_PROPERTY("scalar",scalar)
		;
}
