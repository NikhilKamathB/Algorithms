/**
 * @file main.cpp
 * @brief Contains the main function to run the algorithms library | wrapper for python.
*/

#include <boost/python.hpp>

const std::string greet() {
    return "Hello, World!";
}

BOOST_PYTHON_MODULE(algorithms)
{
    using namespace boost::python;
    def("greet", greet);
}