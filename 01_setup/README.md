#### setup 
apt install cmake <br>
apt install qtdeclarative5-dev <br>

mkdir Your_dir && cd Your_dir<br>
touch main.cpp mainwidget.cpp mainwidget.h<br>
qmake -project<br>
mkdir build && cd build <br>
qmake ../Your_dir.pro<br>
make<br>