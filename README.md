# Coccode

Use Clang

    $ sudo update-alternatives --config c++
    
after that, run a shell script:

    $ sudo apt-get install cmake clang llvm libx11-dev libglfw3-dev libsdl2-dev
    $ sudo update-alternatives --config cc
    $ ./unix_release.sh # or unix_debug
