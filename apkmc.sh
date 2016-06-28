unzip -qo $1 -d temp
ls temp/*.dex | xargs methodcount
rm -rf temp
