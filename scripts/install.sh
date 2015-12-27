# sudo apt-get update
# sudo apt-get upgrade

DEPENDENCIES="avrdude python-pip"
OPTIONAL_PACKAGES="picocom mosh"

sudo apt-get install $DEPENDENCIES
sudo apt-get install $OPTIONAL_PACKAGES

mkdir -p honeyplot/firmware