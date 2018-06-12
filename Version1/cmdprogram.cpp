/*header file - cmdline_header*/

#include <iostream>
#include <cstring>
using namespace std;
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <sstream>

#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

class shiftbit
{
    public:
        void parse(char **argv, int argc);	
        void printArgs();
	void ifunc(string mystr1, int x);
	void sfunc(string mystr1, int x);
	void rfunc(string mystr1, int x);
	void lfunc(string mystr1, int x);
	void ofunc(string mystr1);
	void vfunc(string mystr1);
	void dfunc();
	void hfunc();


    private:     
        char **myargv;
        int myargc;
        vector <int> result={0};
	vector<int> reg1={0};
	vector<int> reg2={0};
	int mystrno1=1;
	int mystrno2=1;
	int mysign1=0, mysign2=0;
	int mycount1=0, mycount2=0;
	string dreg1="0", dreg2="0", dres="0";
	string hreg1="0", hreg2="0", hres="0";
	int lrcount1=0, lrcount2=0;	

			 	            
};

#endif

//cc file - cmdline_cpp 

void shiftbit :: parse(char **argv, int argc)
{
    myargc=argc;
    myargv=argv;
    reg1.resize(1); 
    reg2.resize(1); 
    string temp;
	
   for(int j=1; j<myargc; j++)
   {
	  temp=myargv[j];

	  if(temp[1]=='i')
	  {	
		string mystr1=myargv[j+1];
		ifunc(mystr1,1);
	  
	  }
	  else if(temp[1]=='I')
	  {	
		string mystr1=myargv[j+1];
		ifunc(mystr1,2);
	  
	  }
	  else if(temp[1]=='p')
	  {	
		printArgs();
	  }
   	  else if(temp[1]=='s')
	  {
		string mystr1=myargv[j+1];
		sfunc(mystr1,1);
	  }
     	  else if(temp[1]=='S')
	  {
		string mystr1=myargv[j+1];
		sfunc(mystr1,2);
	  }
    	  else if(temp[1]=='r')
	  {
		string mystr1=myargv[j+1];
		lrcount1++;
		rfunc(mystr1,1);
	  }
    	  else if(temp[1]=='R')
	  {
		string mystr1=myargv[j+1];
		lrcount2++;
		rfunc(mystr1,1);
	  }
    	  else if(temp[1]=='l')
	  {
		string mystr1=myargv[j+1];
		lrcount1++;
		lfunc(mystr1,1);
	  }
    	  else if(temp[1]=='L')
	  {
		string mystr1=myargv[j+1];
		lrcount2++;
		lfunc(mystr1,2);
	  }
    	  else if(temp[1]=='o')
	  {
		string mystr1=myargv[j+1];
		ofunc(mystr1);
	  }
	  else if(temp[1]=='v')
	  {
		string mystr1=myargv[j+1];
		vfunc(mystr1);
	  }
	  else if(temp[1]=='d')
	  {
		dfunc();
	  }
	  else if(temp[1]=='h')
	  {
		hfunc();
	  }
		
   }
	
}

//Function Definitions


void shiftbit :: ifunc(string mystr1, int x)
{
   vector <int> vtemp={0}; 
   int arr[10];
   int b=1;
   int carry=1;	
   int count=0;
   int xy;
   xy=x;	
   string myinput=mystr1;
   string myarr;
   int mresult[10]={0};

   if(myinput[0]=='1')
   {
	if(vtemp.size()>=0)
	{
		vtemp.resize(0);
	}
	vtemp.resize(myinput.length()-1);
	for(int i=1; i<myinput.length();i++)
	{
		if(myinput[i]=='1')
		{
			vtemp[i-1]=1;
		}
		else
		{
			vtemp[i-1]=0;
		}
	}
	vtemp.resize(myinput.length()-1);
	for(int i=0; i<(vtemp.size()); i++)
	{
		if(vtemp[i]==0)
		{
			vtemp[i]=1;
		}
		else if(vtemp[i]==1)
		{
			vtemp[i]=0;
		}
	}
	for(int i=0; i<(vtemp.size()); i++)
	{
		if(vtemp[i]==1)
		{
			count++;
		}
	}
	if(vtemp.size()==count)
	{
		mresult[0]=1;
		for(int i=0; i<(vtemp.size()); i++)
		{
			mresult[i+1]=0;
		}
	
		for(int i=0; i<(vtemp.size()); i++)
		{
			vtemp[i]=mresult[i];
		}		
	}
	else
	{
		for(int i=(vtemp.size())-1; i>=0; i--)
		{
		    mresult[i]=carry+vtemp[i];
		    if(mresult[i]==2)
		    {
			mresult[i]=0;
			carry=1;
		    }
		    else if(mresult[i]==1)
		    {
			mresult[i]=1;
			carry=0;
		    }	
		    else if(mresult[i]==0)
		    {
			mresult[i]=0;
		        carry=0;
		    } 
		}
		for(int i=0; i<(vtemp.size()); i++)
			{
				vtemp[i]=mresult[i];
			}	
	}
   }
   else if (myinput[0]=='0')
   {	
	if(vtemp.size()>=0)
	{
		vtemp.resize(0);
	}
	vtemp.resize(myinput.length()-1);
	for(int i=1; i<myinput.length();i++)
	{
		if(myinput[i]=='1')
		{
			vtemp[i-1]=1;
		}
		else
		{
			vtemp[i-1]=0;
		}
	}
   } 
   if(xy==1)
   {
     if(myinput[0]=='1')
     {
        mysign1=1;
     }
     reg1.resize(vtemp.size());
     for(int i=0; i<vtemp.size(); i++)
     { 
     	reg1[i]=vtemp[i];
     }
     mystrno1=reg1.size();
   }  
   else if(xy==2)
   {
     if(myinput[0]=='1')
     {
        mysign2=1;
     }
     reg2.resize(vtemp.size());
     for(int i=0; i<vtemp.size(); i++)
     { 
     	reg2[i]=vtemp[i];
     }
     mystrno2=reg2.size();
   } 
}	

void shiftbit :: printArgs()
{
  for(int z=0; z<reg1.size(); z++)
  {
	if(reg1[z]==8)
	{
		reg1[z]=0;
	}
   }
   for(int z=0; z<reg2.size(); z++)
   {
	if(reg2[z]==8)
	{
		reg2[z]=0;
	}
   }

   
	string temp; int mycounter=0;
	 for(int j=1; j<myargc; j++)
	 {
		  temp=myargv[j];

		  if(temp[1]=='d')
		  {	
			mycounter++;
			cout<<"Result (Operation 'd'): "<<endl;
			cout<<"Register 1: "<<dreg1<<endl;
			cout<<"Register 2: "<<dreg2<<endl;
			cout<<dres<<endl;	
			
		  
		  }
		  else if(temp[1]=='h')
		  {	
		        mycounter++;
			cout<<"Result (Operation 'h'): "<<endl;
			cout<<"Register 1: "<<hreg1<<endl;
			cout<<"Register 2: "<<hreg2<<endl;		  
			cout<<hres<<endl;
		 }
	}
	if(mycounter==0)
	{	
		   cout<<"Register 1: ";
			reg1.resize(mystrno1);	
		   for(int i=0; i<reg1.size(); i++)
		   {
		     cout<<reg1[i];
		   }

		   cout<<endl;

		   cout<<"Register 2: ";
			reg2.resize(mystrno2);
		   for(int i=0; i<reg2.size(); i++)
		   {
		     cout<<reg2[i];
		   }

		   cout<<endl;
		   //cout<<"Result(Operation 'o'): "<<endl;
		   for(int i=0; i<result.size(); i++)
		   {
			   cout<<result[i];
		   }
	   	   cout<<endl;
		  
	}
		  	

}

void shiftbit :: sfunc(string mystr1, int x)
{	
	vector <int> stemp={0};
	int z; string xz; int xy;
	xy=x;
	if(xy==1)
   	{
     		stemp.resize(reg1.size());
    		for(int i=0; i<stemp.size(); i++)
     		{ 
     			stemp[i]=reg1[i];
     		}
   	}  
   	else if(xy==2)
   	{
    		stemp.resize(reg2.size());
     		for(int i=0; i<stemp.size(); i++)
     		{ 
     			stemp[i]=reg2[i];
     		}
   	} 
	xz=mystr1;
	z=stoi(xz);
	int y=z-stemp.size();
	stemp.insert(stemp.begin(),y,0);
	stemp.resize(z);	
	if(xy==1)
   	{
		mystrno1=z;
     		reg1.resize(stemp.size());
    		for(int i=0; i<reg1.size(); i++)
     		{ 
     			reg1[i]=stemp[i];
     		}
   	}  
   	else if(xy==2)
   	{
		mystrno2=z;
    		reg2.resize(stemp.size());
     		for(int i=0; i<reg2.size(); i++)
     		{ 
     			reg2[i]=stemp[i];
     		}
   	} 
}

void shiftbit :: rfunc(string mystr1, int x)
{
	vector <int> rtemp={0};
	string xz;
	xz=mystr1;
	int xy=x;
	if(xy==1)
   	{
     		rtemp.resize(reg1.size());
    		for(int i=0; i<rtemp.size(); i++)
     		{ 
     			rtemp[i]=reg1[i];
     		}
   	}  
   	else if(xy==2)
   	{
    		rtemp.resize(reg2.size());
     		for(int i=0; i<rtemp.size(); i++)
     		{ 
     			rtemp[i]=reg2[i];
     		}
   	} 
	int itr = (stoi(xz));
	for(int y=1; y<=itr; y++)
	{
		for(int x=rtemp.size(); x!=0; x--)
		{			
			rtemp[x]=rtemp[x-1];			
		} 
	}
	for(int z=0; z<itr; z++)
	{	
		rtemp[z]=8; 
	}
	if(xy==1)
   	{
		mystrno1=rtemp.size();
     		reg1.resize(rtemp.size());
    		for(int i=0; i<reg1.size(); i++)
     		{ 
     			reg1[i]=rtemp[i];
     		}
   	}  
   	else if(xy==2)
   	{
		mystrno2=rtemp.size();
    		reg2.resize(rtemp.size());
     		for(int i=0; i<reg2.size(); i++)
     		{ 
     			reg2[i]=rtemp[i];
     		}
   	} 	
}

void shiftbit :: lfunc(string mystr1, int x)
{
	vector <int> ltemp={0};
	string xz;
	xz=mystr1;
	int xy=x;
	if(xy==1)
   	{
     		ltemp.resize(reg1.size());
    		for(int i=0; i<ltemp.size(); i++)
     		{ 
     			ltemp[i]=reg1[i];
     		}
   	}  
   	else if(xy==2)
   	{
    		ltemp.resize(reg2.size());
     		for(int i=0; i<ltemp.size(); i++)
     		{ 
     			ltemp[i]=reg2[i];
     		}
   	} 
	int itr = (stoi(xz));
	for(int y=1; y<=itr; y++)
	{
		for(int x=0; x<ltemp.size(); x++)
		{			
			ltemp[x]=ltemp[x+1];	
		} 
	}
	for(int z=(ltemp.size()-1); z>ltemp.size()-1-itr; z--)
	{	
		ltemp[z]=8; 
	}
	if(xy==1)
   	{
		mystrno1=ltemp.size();
     		reg1.resize(ltemp.size());
    		for(int i=0; i<reg1.size(); i++)
     		{ 
     			reg1[i]=ltemp[i];
     		}
   	}  
   	else if(xy==2)
   	{
		mystrno2=ltemp.size();
    		reg2.resize(ltemp.size());
     		for(int i=0; i<reg2.size(); i++)
     		{ 
     			reg2[i]=ltemp[i];
     		}
   	} 
}

void shiftbit :: vfunc(string mystr1)
{
	string x;
	x=mystr1;
	int vcc=stoi(x);
	for(int z=0; z<reg1.size(); z++)
	{
		if(reg1[z]==8)
		{
			reg1[z]=vcc;
		}	
	}
	for(int z=0; z<reg2.size(); z++)
	{
		if(reg2[z]==8)
		{
			reg2[z]=vcc;
		}	
	}
}

void shiftbit :: dfunc()
{
	reg1.resize(mystrno1);
	reg2.resize(mystrno2);
	dreg1.resize(reg1.size());
	dreg2.resize(reg2.size());
	dres.resize(result.size());
	int dec1=0,dec2=0,dec3=0;
	int base=1;
	if(mysign1==0)
	{	
		for(int i=dreg1.size()-1; i>=0; i--)
		{
			int x,y;
			if(reg1[i]==0 || reg1[i]==8)
			{
				dreg1[i]='0';
				y=0;
			}
			else if(reg1[i]==1)
			{
				dreg1[i]='1';
				y=1;
			}	
			x=y;
			dec1=dec1+(x*base);
			base=base*2;
		}
	}
	else if(mysign1==1)
	{
		dreg1.resize(reg1.size());
		for(int i=dreg1.size()-1; i>=0; i--)
		{
			if(reg1[i]==0 || reg1[i]==8)
			{
				y=1;
				dreg1[i]=1;
			}
			else if(reg1[i]==1)
			{
				y=0;
				dreg1[i]=0;
			}		
		}


		for(int i=0; i<(dreg1.size()); i++)
		{
			if(dreg1[i]==1)
			{
				count++;
			}
		}
		if(dreg1.size()==count)
		{
			mresult[0]=1;
			for(int i=0; i<(dreg1.size()); i++)
			{
				mresult[i+1]=0;
			}
		}
		else
		{				
			for(int i=(dreg1.size())-1; i>=0; i--)
			{

			    mresult[i]=carry+htemp1[i];
			    if(mresult[i]==2)
			    {
				mresult[i]=0;
				carry=1;
			    }
			    else if(mresult[i]==1)
			    {
				mresult[i]=1;
				carry=0;
			    }	
			    else if(mresult[i]==0)
			    {
				mresult[i]=0;
				carry=0;
			    } 
			   
			}
		}
		for(int i=0; i<(dreg1.size()); i++)
		{
			dreg1[i]=mresult[i];
		}
		for(int i=dreg1.size()-1; i>=0; i--)
		{
			if(dreg1[i]==0)
			{
				y=0;
			}
			else if(dreg1[i]==1)
			{
				y=1;
			}
			x=y;
			dec1=dec1+(x*base);
			base=base*2;
		}

	   }
	
	}	
	base=1;
	if(mysign2==0)
	for(int i=dreg2.size()-1; i>=0; i--)
	{	
		int x,y;
		if(reg2[i]==0 || reg2[i]==8)
		{
			dreg2[i]='0';
			y=0;
		}
			else if(reg2[i]==1)
			{
				dreg2[i]='1';
				y=1;
			}	
			x=y;
			dec2=dec2+(x*base);
			base=base*2;
	}
	
	base=1;
	for(int i=dres.size()-1; i>=0; i--)
	{	
		int x,y;
		if(result[i]==0 || result[i]==8)
		{
			dres[i]='0';
			y=0;
		}
		else if(result[i]==1)
		{
			dres[i]='1';
			y=1;
		}
		else
		{
			dres[i]='0';
		}	
		x=y;
		dec3=dec3+(x*base);
		base=base*2;
	}
	if(!dreg1.empty())
	{
		if(mysign1==1)
		{
			dreg1=dreg1+"(-"+to_string(dec1)+")";
		}
		else
		{
			dreg1=dreg1+"("+to_string(dec1)+")";
		}
	}
	else
	{
		string x;
		for(int i=0; i<mystrno1; i++)
		{
			x[i]='0';
		}
		dreg1=x+"(0)";	
	}
	if(!dreg2.empty())
	{
		if(mysign2==1)
		{
			dreg2=dreg2+"(-"+to_string(dec2)+")";
		}
		else
		{
			dreg2=dreg2+"("+to_string(dec2)+")";
		}
	}
	else
	{
		string x;
		for(int i=0; i<mystrno2; i++)
		{
			x[i]='0';
		}
		dreg2=x+"(0)";
	}
	if(!dres.empty())
	{
		dres=dres+"("+to_string(dec3)+")";
	}
	else
	{
		dres="0(0)";
	}
}

void shiftbit :: hfunc()
{
	string temp;
	vector <int> htemp1={0};
	vector <int> htemp2={0};
	int bin1; int bin2; int bin3; int tic; int y1=1; int y2=1; int y3=1;
	char hex1[100]={'0'}; char hex2[100]={'0'}; char hex3[100]={'0'};
	string d1reg1; string d1reg2; string d1res;	
	int dec1=0,dec2=0,dec3=0;
	int base=1;	
	int x=0; int y=0;
	int mresult[10]={0};
	int carry=1;
	int count=0;
	d1reg1.resize(reg1.size());
	if(mysign1==0)
	{
		for(int i=d1reg1.size()-1; i>=0; i--)
		{
			if(reg1[i]==0 || reg1[i]==8)
			{
				d1reg1[i]='0';
				y=0;
			}
			else if(reg1[i]==1)
			{
				d1reg1[i]='1';
				y=1;
			}
			x=y;
			dec1=dec1+(x*base);
			base=base*2;
		}
	
	}
	else if (mysign1==1)
	{
		htemp1.resize(d1reg1.size());
		for(int i=d1reg1.size()-1; i>=0; i--)
		{
			if(reg1[i]==0 || reg1[i]==8)
			{
				y=1;
				htemp1[i]=1;
			}
			else if(reg1[i]==1)
			{
				y=0;
				htemp1[i]=0;
			}		
		}


		for(int i=0; i<(htemp1.size()); i++)
		{
			if(htemp1[i]==1)
			{
				count++;
			}
		}
		if(htemp1.size()==count)
		{
			mresult[0]=1;
			for(int i=0; i<(htemp1.size()); i++)
			{
				mresult[i+1]=0;
			}
		}
		else
		{				
			for(int i=(htemp1.size())-1; i>=0; i--)
			{

			    mresult[i]=carry+htemp1[i];
			    if(mresult[i]==2)
			    {
				mresult[i]=0;
				carry=1;
			    }
			    else if(mresult[i]==1)
			    {
				mresult[i]=1;
				carry=0;
			    }	
			    else if(mresult[i]==0)
			    {
				mresult[i]=0;
				carry=0;
			    } 
			   
			}
		}
		for(int i=0; i<(htemp1.size()); i++)
		{
			htemp1[i]=mresult[i];
		}
		d1reg1.resize(htemp1.size());
		for(int i=htemp1.size()-1; i>=0; i--)
		{
			if(htemp1[i]==0)
			{
				d1reg1[i]='0';
				y=0;
			}
			else if(htemp1[i]==1)
			{
				d1reg1[i]='1';
				y=1;
			}
			x=y;
			dec1=dec1+(x*base);
			base=base*2;
		}

	}
	
	base=1;
	d1reg2.resize(reg2.size());
	x=0; y=0;
	if(mysign2==0)
	{
		for(int i=d1reg2.size()-1; i>=0; i--)
		{
			if(reg2[i]==0 || reg2[i]==8)
			{
				d1reg2[i]='0';
				y=0;
			}
			else if(reg2[i]==1)
			{
				d1reg2[i]='1';
				y=1;
			}
			x=y;
			dec2=dec2+(x*base);
			base=base*2;
		}
	
	}
	else if (mysign2==1)
	{
		htemp2.resize(d1reg2.size());
		for(int i=d1reg2.size()-1; i>=0; i--)
		{
			if(reg2[i]==0 || reg2[i]==8)
			{
				d1reg2[i]='1';
				y=1;
				htemp2[i]=1;
			}
			else if(reg2[i]==1)
			{
				d1reg2[i]='0';
				y=0;
				htemp2[i]=0;
			}		
		}


		for(int i=0; i<(htemp2.size()); i++)
		{
			if(htemp2[i]==1)
			{
				count++;
			}
		}
		if(htemp2.size()==count)
		{
			mresult[0]=1;
			for(int i=0; i<(htemp2.size()); i++)
			{
				mresult[i+1]=0;
			}
		}
		else
		{				
			for(int i=(htemp2.size())-1; i>=0; i--)
			{

			    mresult[i]=carry+htemp2[i];
			    if(mresult[i]==2)
			    {
				mresult[i]=0;
				carry=1;
			    }
			    else if(mresult[i]==1)
			    {
				mresult[i]=1;
				carry=0;
			    }	
			    else if(mresult[i]==0)
			    {
				mresult[i]=0;
				carry=0;
			    } 
			   
			}
		}
		for(int i=0; i<(htemp2.size()); i++)
		{
			htemp2[i]=mresult[i];
		}
		d1reg2.resize(htemp2.size());
		for(int i=htemp2.size()-1; i>=0; i--)
		{
			if(htemp2[i]==0)
			{
				d1reg2[i]='0';
				y=0;
			}
			else if(htemp2[i]==1)
			{
				d1reg2[i]='1';
				y=1;
			}
			x=y;
			dec2=dec2+(x*base);
			base=base*2;
		}
	}
	base=1;
	d1res.resize(result.size());
	x=0; y=0;
	for(int i=d1res.size()-1; i>=0; i--)
	{
			if(result[i]==0 || result[i]==8)
			{
				d1res[i]='0';
				y=0;
			}
			else if(result[i]==1)
			{
				d1res[i]='1';
				y=1;			
			}
			x=y;
			dec3=dec3+(x*base);
			base=base*2;

	}

	bin1=dec1;
	bin2=dec2;	
	bin3=dec3;
	while(bin1!=0)
	{
		tic=bin1%16;	
		if(tic<10)
		{
			tic=tic+48;
		}
		else
		{
			tic=tic+55;
		}
		hex1[y1++]=tic;
		bin1=bin1/16;
	}
	
	while(bin2!=0)
	{
		tic=bin2%16;	
		if(tic<10)
		{
			tic=tic+48;
		}
		else
		{
			tic=tic+55;
		}
		hex2[y2++]=tic;
		bin2=bin2/16;
	}
	while(bin3!=0)
	{
		tic=bin3%16;	
		if(tic<10)
		{
			tic=tic+48;
		}
		else
		{
			tic=tic+55;
		}
		hex3[y3++]=tic;
		bin3=bin3/16;
	}
	if(!d1reg1.empty())
	{
		if(mysign1==1)
		{
			hreg1=d1reg1+"(-"+"0X"+hex1+")";
		}
		else
		{
			hreg1=d1reg1+"("+"0X"+hex1+")";
		}
	}
	else
	{
		string x;
		for(int i=0; i<mystrno1; i++)
		{
			x[i]='0';
		}
		hreg1=x+"(0X00)";
	}
	if(!d1reg2.empty())
	{
		if(mysign2==1)	
		{
			hreg2=d1reg2+"(-"+"0X"+hex2+")";
		}
		else
		{
			hreg2=d1reg2+"("+"0X"+hex2+")";
		}
	}
	else
	{
		string x;
		for(int i=0; i<mystrno2; i++)
		{
			x[i]='0';
		}
		hreg2=x+"(0X00)";
	}
	if(!d1res.empty())
	{
		if(hex1>hex2 && mysign1==1)
		{
			hres=d1res+"(-"+"0X"+hex3+")";	
		}
		else if(hex1<hex2 && mysign2==1) 
		{
			hres=d1res+"(-"+"0X"+hex3+")";	
		}
		else
		{
			hres=d1res+"("+"0X"+hex3+")";	
		}
	}
	else
	{
		hres="0(0x00)";
	}
}


void shiftbit :: ofunc(string mystr1)
{
  string x;
  x=mystr1;
  int mysize=0;
  int carry=0;
  int arr1[10], arr2[10]; 
  if(x.length()==1)
  {
	  for(int i=0; i<mystrno1; i++)
	  {
	  	arr1[i]=reg1[i];	
	  }

	  for(int i=0; i<mystrno2; i++)
	  {
	  	arr2[i]=reg2[i];	
	  }

	  if(reg1.size()>reg2.size())
	  {
		mysize=reg1.size();
		int x1=mysize-reg2.size();
		reg2.resize(mysize);
		for(int i=1; i<=x1; i++)
		{
			reg2.insert(reg2.begin(), 0);
		}

	  }
	  else if(reg1.size()<reg2.size())
	  {
		mysize=reg2.size();
		for(int i=0; i<(mysize-reg1.size()); i++)
		{
			reg1.insert(reg1.begin(), 0);
		}

	  }
	  else
	  {
		mysize=reg1.size();
	  } 
	
	  if(x[0]=='+')
	  {
		result.resize(mysize);
		for(int i=(mysize)-1; i>=0; i--)
		{
		    result[i]=carry+reg1[i]+reg2[i];
		    if(result[i]==2)
		    {
			result[i]=0;
			carry=1;
		    }
		    else if(result[i]==1)
		    {
			result[i]=1;
			carry=0;
		    }	
		    else if(result[i]==0)
		    {
			result[i]=0;
		        carry=0;
		    }
		    else if(result[i]==3)
		    {
			result[i]=1;
		        carry=1;
		    } 
			
		}
		
		if (carry==1)
		{
			result.resize(mysize);
			result.insert(result.begin(), 1);
		}
		for(int i=0; i<mystrno1; i++)
		{
		  	reg1[i]=arr1[i];	
		}

		for(int i=0; i<mystrno2; i++)
		{
		  	reg2[i]=arr2[i];	
		}   
		
		
	  }
	  else if(x[0]=='-')
	  {
		int borrow=0;
		result.resize(mysize);
		for(int i=(mysize)-1; i>=0; i--)
		{
			    int y=(reg1[i]-reg2[i]);
			    if(y==1 && borrow==0)
			    {
				result[i]=1;
				borrow=0;
			    }
			    else if(y==0 && borrow==0)
			    {
				result[i]=0;
				borrow=0;
			    }
			    else if((y==-1 && borrow==0)||(y==0 && borrow==1))
			    {
				result[i]=1;
				borrow=1;
			    }
			    else if(y==1 && borrow==1)
			    {
				result[i]=0;
				borrow=0;
			    }
			    else if(y==-1 && borrow==1)
			    {
				result[i]=0;
				borrow=1;
			    }
			        
		}
		
		/*if (borrow==1)
		{
			int count=0;
			for(int i=0; i<(result.size()); i++)
			{
				if(result[i]==0)
				{
					result[i]=1;
				}
				else if(result[i]==1)
				{
					result[i]=0;
				}
			}
	
			for(int i=0; i<(result.size()); i++)
			{
					if(result[i]==1)
					{
						count++;
					}
			}
			if(result.size()==count)
			{
				result[0]=1;
				for(int i=0; i<(result.size()); i++)
				{
					result[i+1]=0;
				}	
			}
			else
			{
				for(int i=(result.size())-1; i>=0; i--)
				{
					    result[i]=carry+reg2[i];
					    if(result[i]==2)
					    {
						result[i]=0;
						carry=1;
					    }
					    else if(result[i]==1)
					    {
						result[i]=1;
						carry=0;
					    }	
					    else if(result[i]==0)
					    {
						result[i]=0;
						carry=0;
					    }    
				}
			}
		}*/
		
}

}
}
   	  

//main.cpp


int main(int argc, char **argv)
{
    int argc1;
    char **argv1;
    argc1=argc;
    argv1=argv;  
    int y;
    shiftbit * shiftobj = new shiftbit();
    shiftobj->parse(argv1,argc1);  	
    return 0;

}

