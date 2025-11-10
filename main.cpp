#include <cstdio>
#include <iostream>
#include "func.h"
//#include "calcu.h"
#include "asio/serial_port.hpp"

using namespace std;


typedef float(* Fp)(float, float);
int http_cli(char *web, char *file);

int main()
{
	//Func
	float x=720, y=18, z;
	z = add_f(x, y);
	printf("add = %f\n", z);
	z = sub_f(x, y);
	printf("sub = %f\n", z);
	z = mul_f(x, y);
	printf("mul = %f\n", z);
	z = div_f(x, y);
	printf("div = %f\n", z);

	//Func pointer
	Fp fp_arr[] = {add_f, sub_f, mul_f, div_f};
	for(int n=0; n<4; ++n)
		printf("%f\n", fp_arr[n](x, y));

	//3rd dll
	//printf("3rd div = %d\n", div_i(12, 3));
  
	//http
	http_cli((char *)"www.baidu.com", (char *)"/index.html");
	
	
	//serial
	asio::io_context io;  
	asio::serial_port sp(io,"COM48");  

	//设置串口参数  
	sp.set_option(asio::serial_port::baud_rate(9600));  
	sp.set_option(asio::serial_port::flow_control());  
	sp.set_option(asio::serial_port::parity());  
	sp.set_option(asio::serial_port::stop_bits());  
	sp.set_option(asio::serial_port::character_size(8));  

	asio::error_code err;  
	while(true)  
	{  
		char buf[]="hello";  
		int nWrite = sp.write_some(asio::buffer(buf), err);  
		if(err)  
		{  
			cout<<"write_some err,errmessage:"<<endl;  
			break;  
		}  
		else  
		{  
			char buf[1024];  
			sp.read_some(asio::buffer(buf), err);  
			if(!err)  
			{  
				cout<<"recv data:"<<buf<<endl;  
			}else
			{
				cout<<"recv err:"<<err<<endl;
			}
		}  
	}  
	io.run();
	
	return 0;
}