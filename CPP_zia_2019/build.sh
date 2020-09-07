#!/usr/bin/bash

# Skip if conan is installed and install it otherwise

if ! [ -x "$(command -v conan)" ]; then
    # Install conan
    sudo pip install conan --upgrade

    # Set a default profile for conan and set the compiler at c++11
    conan profile new default --detect
    conan profile update settings.compiler.libcxx=libstdc++11 default

    # Add and / or update needed remotes for this project
    conan remote add conan_center https://api.bintray.com/conan/conan/conan-center
    conan remote add epitech https://api.bintray.com/conan/epitech/public-conan
    conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
fi

# Create the logs repository if it not exists

mkdir -p logs

# Build if needed, make otherwise

if [ ! -d "./build" ] || [ "$1" == "-b" ] || [ "$1" == "--build" ]
then
    conan remote update conan_center https://api.bintray.com/conan/conan/conan-center
    conan remote update epitech https://api.bintray.com/conan/epitech/public-conan
    conan remote update bincrafters https://api.bintray.com/conan/bincrafters/public-conan

    # Remove old build folder and procces to a new build

    rm -rf build
    mkdir -p build && cd build && conan install ../conanfile.txt --build=missing && cmake .. && cd ..
else
    #  Make in the build repository

    cd build && cmake --build . -- -j 4 && cd ..
fi

# doc_gen installation
if [ "$1" == "--config" ]; then

    # Checking if the docgen.conf file exists in /usr/bin, copy it from the config folder otherwise
    if [ ! -f "/usr/bin/docgen.conf" ]; then
        sudo cp config/docgen.conf /usr/bin/
        echo "Configuration for doc_gen has been installed."
    else
        echo "Configuration already done."
    fi

    # Checking if CppHeaderParser as been installed
    pip list | grep -F CppHeaderParser
    status=$?

    # If the CppHeaderParser packet hasn't been found, downloading it.
    if [ $status -ne 0 ]; then
        echo "CppHeaderParser not found, fetching ..."
        sudo pip install CppHeaderParser --upgrade
    else
        echo "CppHeaderParser already installed, skipping ..."
    fi

    echo "doc_gen dependencies installation finished."
fi


# Set up the doxygen documentation and launch it from firefox
if [ "$1" == "--doc" ]; then

    doxygen Doxyfile
    mkdir -p doc
    mv html doc
    mv latex doc
    cd doc/html
    firefox index.html

fi