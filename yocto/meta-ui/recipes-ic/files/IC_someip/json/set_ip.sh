# Python 스크립트 실행
python3 /opt/IC_someip/json/change_ip.py

# Python 스크립트에서 사용한 인터페이스 이름을 받아와서 경로 추가
INTERFACE=$(python3 -c "import netifaces as ni; iface = next(i for i in ni.interfaces() if i != 'lo' and ni.AF_INET in ni.ifaddresses(i)); print(iface)")

# 멀티캐스트 경로 추가

echo "Multicast route added for interface $INTERFACE"
