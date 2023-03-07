apt install -y expect
apt install -y lsb-release
apt install -y gnupg
expect -c "
    spawn   dpkg -i mysql-apt-config_0.8.14-1_all.deb
    expect  {Which MySQL product do you wish to configure?} {send 1\n}
    expect  {Which server version do you wish to receive?} {send 1\n}
    expect  {Which MySQL product do you wish to configure?} {send 4\n}
    expect  eof
"
apt update
expect -c "
    set timeout 100
    spawn   apt install -y mysql-server
    expect  {Enter root password:} {send root\n}
    expect  {Re-enter root password:} {send root\n}
    expect  eof
"