# sudo apt-get update
# sudo apt-get upgrade

DEPENDENCIES="avrdude picocom python-pip"

sudo apt-get install $DEPENDENCIES

mkdir -p controller/firmware