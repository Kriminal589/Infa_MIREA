#include "basic_file.hpp"
/*
 Object_root
 Object_root Object_1
 Object_root Object_2
 Object_root Object_3
 Object_3 Object_4
 Object_3 Object_3
 
 
 Object_root
 Object_root Object_1
 Object_root Object_2
 Object_root Object_3
 Object_3 Object_4
 Object_3 Object_5
 Object_6 Object_6
 */

int main()
{
    Class1 app;
    app.buildtree();
    return app.start();
    return 0;
}
