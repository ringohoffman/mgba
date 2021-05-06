mkdir -p build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr/local ..
make all
sudo make install
cd ..
mgba -3 /home/ringo/Desktop/mgba/game/emerald.gba -c game/emerald.cheats
