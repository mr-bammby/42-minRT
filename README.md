# 42-miniRT

WSL / Ubuntu
- Launch Xming
- export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0