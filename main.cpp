#include <conio.h> 
#include <graphics.h> 
#include <stdio.h>
#include<math.h> 

#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)
float PI=3.14;
void Export2SVG(int width, int height)
{
  	FILE *fp = fopen("1035.svg", "w");
  	fprintf(fp, "<svg width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\" fill=\"none\" xmlns=\"http://www.w3.org/2000/svg\"  version=\"1.1\">",width,height,width,height);
  	
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(250,174,40);stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>",  150, 100, 200, 35);
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(253,255,255);stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", 150, 135, 200, 35);
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(33,148,31);stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>",  150,  170, 200, 35);
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(185, 190, 192);stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", 125, 100, 25, 275);
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(160, 249, 235 );stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", 100, 375, 75, 25);
    	
    fprintf(fp,"\n<circle style=\"stroke:RGB(0,0,136);stroke-width:2\" r=\"17\" cx=\"250\" cy=\"152\"></circle>");
    int x,y,a=250,b=152,r=17;
	float PI=3.14;
	
	
	for(int i=0;i<=360;i=i+15)
	{
		x=r*cos(i*PI/180);
		y=r*sin(i*PI/180);
		fprintf(fp,"\n<line style=\"stroke:RGB(0,0,136);stroke-width:2\" x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\"></line>",a,b,a+x,b-y);
	}
	
  	printf("1035.svg created successfully!\n");
  	fprintf(fp, "\n </svg>\n");
    fclose(fp);
}

void Export2HTML(int width, int height)
{
  	
  	FILE *fp = fopen("1035.html", "w");
  	fprintf(fp, "<!DOCTYPE html>\n<html>\n<body>\n"); 
	fprintf(fp, "<svg width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\" fill=\"none\" xmlns=\"http://www.w3.org/2000/svg\"  version=\"1.1\">",width,height,width,height);
  	
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(250,174,40);stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>",  150, 100, 200, 35);
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(253,255,255);stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", 150, 135, 200, 35);
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(33,148,31);stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>",  150,  170, 200, 35);
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(185, 190, 192);stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", 125, 100, 25, 275);
	fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:RGB(160, 249, 235 );stroke:black;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", 100, 375, 75, 25);
    		
    fprintf(fp,"\n<circle style=\"stroke:RGB(0,0,136);stroke-width:2\" r=\"17\" cx=\"250\" cy=\"152\"></circle>");
    int x,y,a=250,b=152,r=17;
	float PI=3.14;
	
	
	for(int i=0;i<=360;i=i+15)
	{
		x=r*cos(i*PI/180);
		y=r*sin(i*PI/180);
		fprintf(fp,"\n<line style=\"stroke:RGB(0,0,136);stroke-width:2\" x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\"></line>",a,b,a+x,b-y);
	}
	
    fprintf(fp, "\n </svg>\n");
    fprintf(fp, "\n</body>\n</html>\n");
    fclose(fp);
  	printf("1035.html created successfully!\n");
}


void flood(int x, int y, int new_col, int old_col) 
{ 
    if (getpixel(x, y) == old_col)
	{ 
        putpixel(x, y, new_col); 
        	
        flood(x + 1, y, new_col, old_col); 
        
       
        flood(x - 1, y, new_col, old_col); 
        
       
        flood(x, y + 1, new_col, old_col); 
        
        
        flood(x, y - 1, new_col, old_col); 
    } 
}
//Driver Code
int main() 
{ 
    // Initialize of gdriver with 
    // DETECT macros 
    int gdriver = DETECT, gmode; 
    int x,y;
    initgraph(&gdriver, &gmode, " "); 
    //Setting the margin
    line (0,0,700,0);
    line(500,0,0,0);
	// Initialize structure of 
    // the flag
    //initwindow(1000,1000);
    
    
    //Boundary
    line(0,0,700,0);
    line(0,0,0,500);
    line(700,0,700,500);
    line(0,500,700,500);
    
    // draw the flag
    //orange rect
    rectangle(150,100,350,135);
    
    // white rect
     rectangle(150,135,350,170);
     
     //green rect
      rectangle(150,170,350,205);
      //stand
       rectangle(125,100,150,375);
       // base
        rectangle(100,375,175,400);
        
        //colour
        flood(151,134,6,0);
        flood(151,169,15,0);
        flood(151,204,2,0);
    	flood(126,374,8,0);
    	flood(101,399,11,0);
		flood(251,151,15,0);
    	
    	
    	//Chakra
    	setcolor(0);
    	circle(250,152,17);   //center - 250,152- radius line co ordinate- 250,152,233,152
    	setcolor(1);
    	line(250,152,233,152);
    	//rotate(1,250,152,22.5);
    	for(int i=0;i<=360;i=i+15)
	{
		x=17*cos(i*PI/180);
		y=17*sin(i*PI/180);
		line(250,152,250+x,152-y);
	}
    
    Export2HTML(1500,1500);
	Export2SVG(1500,1500);
    
    getch();
  
    // Close the initialized gdriver 
    closegraph();
   
	return 0; 
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
