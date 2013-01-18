#! /bin/bash
TEST_DIR=`pwd`
TMPDIR=`mktemp -d`

cd $TMPDIR
create_new_cppcmsskel
cd tools
cp $TEST_DIR/config2.py config.py
./init.py
cd ../app
mkdir build
cd build 
cmake ..
make
./TatoWiki -c ../config.js
