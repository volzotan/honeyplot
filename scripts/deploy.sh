REMOTE_SERVER=honeyplot
REMOTE_DIR=/home/pi/controller

cd ..
tar -zcf controller.tar.gz controller
ssh $REMOTE_SERVER "mkdir -p $REMOTE_DIR"
scp controller.tar.gz $REMOTE_SERVER:$REMOTE_DIR
ssh $REMOTE_SERVER 'bash -s' < scripts/update.sh
rm controller.tar.gz