#Introduction to cppcmsskel


Cppcmsskel is intented to be a framework over [cppcms](http://cppcms.com/wikipp/en/page/main)
which is itself a framework in C++ to create website


The goal of cppcms is to provide tools to generate automatically new projets/new classes while
following a MVC-like design pattern and a strict naming convention of files/classes/variables

**NOTE:** the project is still at a very early stage, so maybe not production-ready 
(the underlying cppcms framework is however already pretty stable), it's also mean
the I'm currently writing the documentation and so, also don't hesitate to report any ideas/things missings/bugs etc.

#Requirement for cppcmsskel

For this to work we admit you have already cppcms and cppdb (compiled with sqlite3 support, though
I will try to remove the mandatory dependency to cppdb in the future to make it optional)

you will also need:

 * python3 (only needed to generate code, the final code is purely c++, and the produced executable is standalone)
 * sqlite3 
 * cmake
 * a compiler supporting at least some c++11 (it should compile fine with at least gcc > 4.6 / clang > 3.0)

#Installation instruction
    

    git clone git://github.com/allan-simon/cppcms-skeleton.git
    cd cppcms-skeleton
    mkdir build ; cd build ; cmake .. ; make ; make install

Note: make install of course require root priviledges 

Once it's done you should be able to start your first project with

#Creating a new project 

    mkdir new_website ; cd new_website
    create_new_cppcmsskel
    cd tools
    
then you need to create a config.py file, you can use the example in the "tests"
directory cppcmsskel to get a quick working website or you can create your own
one based on the config.py.example file 

one done run the init.py script

    ./init.py

that will generate the code
now you can compile your website by doing 

    cd ../app 
    mkdir build ; cd build ; cmake .. ; make 

it should compile without problems (admitting you've not yet start to add your own code),
if not please submit a bug report

after to launch the website you can do 

    ./yourwebsite -c path/to/your/config.js

the one provided by default will run in standalone mode on the port 8080

##More documentation 

Some additional information can be found here [https://github.com/allan-simon/cppcms-skeleton/wiki](https://github.com/allan-simon/cppcms-skeleton/wiki)

**MORE TO BE ADDED SOON**
