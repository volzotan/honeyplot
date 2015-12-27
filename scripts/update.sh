FOLDER=honeyplot

echo ""
echo "UPDATING"

cd $FOLDER
sudo rm -rf controller
tar -zxpf controller.tar.gz && rm controller.tar.gz
