#include <GL\glew.h> // A cross-platform open-source C/C++ extension loading library
#include <stdlib.h>
#include <GL\freeglut.h> // handle the window-managing operations
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <windows.h>
#include <playsoundapi.h>
using namespace std;
GLint win_width = 700,
win_hight = 700;



int times;
///case1
float rotat;
///////////////////lightt
GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_position[] = { 0.3,3,10,0 };
GLfloat shininess[] = { 2 };





//case2
float flag0, flag00, flag1, flag2, flag01,flag02;
////case 3 wesal
float flag0w;
float flag1w;
float flag2w;
float flag3w;
float flag4w;
float flag5w;
float flag6w;
float flag7w, flag8w, flag9w, flag10w, flag11w;
//
////case 4
float flag1r;
float flag2r;
float flag3r;
float flag4r;
float flag5r;
float flag6r;
float flag7r;
float flag8r;
float flag9r;
float flag10r;
float flag11r;

//case5 variables jumanah
float flag1j, flag2j, flag3j;

//case 6
float flag1t;
float flag2t;
float flag3t;
float flag4t;
float flag5t;
float flag6t;
float flag7t;
//float flag3; //if you have image 3 add and your name
float transValueX, transValueY, transValueZ;
///* square vertices */
GLfloat vertA[3] = { 0.3, 0.3, 0 };
GLfloat vertB[3] = { -0.3, 0.3, 0 };
GLfloat vertC[3] = { -0.3, -0.3, 0 };
GLfloat vertD[3] = { 0.3, -0.3, 0 };

/*square2 vertices */
GLfloat vert2A[3] = { 0.20, 0.20, 0 };
GLfloat vert2B[3] = { -0.20, 0.20, 0 };
GLfloat vert2C[3] = { -0.20, -0.20, 0 };
GLfloat vert2D[3] = { 0.20, -0.20, 0 };

//
/*square3 vertices */
GLfloat vert3A[3] = { 0.42, 0.27, 0 };
GLfloat vert3B[3] = { -0.42, 0.27, 0 };
GLfloat vert3C[3] = { -0.42, -0.27, 0 };
GLfloat vert3D[3] = { 0.42, -0.27, 0 };

//// buffers
GLuint earth_image,
//
//case 2
choice_img,
question_img,


/////case 3 //wesal
threeR_image,
garbage_img,
off_image,
publictrans_image,
walk_image,
bike_image,
pollution_img,
energyrecours_image,
think_img,
//
////case4 reuse ragahd
idea_img,
pbag_img,
water_imge,
ocean_image,
trash1_img,
trash2_img,
noplastic_img,
ecobag_image,
reusee_img,
rewater_img,
jarj_img,
//
//case 5 recycle //juma 
factory_img,
organicj_img,
compostj_img,

/// case 6 zero waste
zerowaste_img,
check_img,
refuse_img,
healthy_img,
bestchoice_img;

//path for image
char image1Path[] = "D:/ComputerGraphicsProjectGroup10/texture/er8.bmp"; //Change path with your path

//case 2////
char choicePath[] = "D:/ComputerGraphicsProjectGroup10/texture/choice.bmp";
char questionPath[] = "D:/ComputerGraphicsProjectGroup10/texture/question.bmp";

///case 3 //wesal
char threeRPath[] = "D:/ComputerGraphicsProjectGroup10/texture/threeR.bmp";
char garbagePath[] = "D:/ComputerGraphicsProjectGroup10/texture/garbage.bmp";
char offPath[] = "D:/ComputerGraphicsProjectGroup10/texture/off.bmp";
char publictransPath[] = "D:/ComputerGraphicsProjectGroup10/texture/publictrans.bmp";
char walkPath[] = "D:/ComputerGraphicsProjectGroup10/texture/walk.bmp";
char bikePath[] = "D:/ComputerGraphicsProjectGroup10/texture/bike.bmp";
char pollutionPath[] = "D:/ComputerGraphicsProjectGroup10/texture/pollution.bmp";
char energyrecoursPath[] = "D:/ComputerGraphicsProjectGroup10/texture/energyrecours.bmp";
char thinkPath[] = "D:/ComputerGraphicsProjectGroup10/texture/think.bmp";
///case 4 ragahd
char ideaPath[] = "D:/ComputerGraphicsProjectGroup10/texture/idea.bmp";
char pbagPath[] = "D:/ComputerGraphicsProjectGroup10/texture/pbag.bmp";
char waterPath[] = "D:/ComputerGraphicsProjectGroup10/texture/water.bmp";
char oceanPath[] = "D:/ComputerGraphicsProjectGroup10/texture/oceant.bmp";
char trash1Path[] = "D:/ComputerGraphicsProjectGroup10/texture/trash1.bmp";
char trash2Path[] = "D:/ComputerGraphicsProjectGroup10/texture/trash2.bmp";
char noplasticPath[] = "D:/ComputerGraphicsProjectGroup10/texture/no-plastic.bmp";
char ecobagPath[] = "D:/ComputerGraphicsProjectGroup10/texture/ecobag.bmp";
char reuseePath[] = "D:/ComputerGraphicsProjectGroup10/texture/reusee.bmp";
char rewaterPath[] = "D:/ComputerGraphicsProjectGroup10/texture/rewater.bmp";
char jarPath[] = "D:/ComputerGraphicsProjectGroup10/texture/money-jar.bmp";
//case 5 jumanh
char factoryPath[] = "D:/ComputerGraphicsProjectGroup10/texture/factory.bmp"; //Change path with your path
char organicPath[] = "D:/ComputerGraphicsProjectGroup10/texture/organic.bmp"; //Change path with your path
char composotPath[] = "D:/ComputerGraphicsProjectGroup10/texture/compost.bmp";
//case 6
char zerowastePath[] = "D:/ComputerGraphicsProjectGroup10/texture/zero-waste.bmp";
char checkPath[] = "D:/ComputerGraphicsProjectGroup10/texture/check.bmp";
char refusePath[] = "D:/ComputerGraphicsProjectGroup10/texture/refuse.bmp";
char healthyPath[] = "D:/ComputerGraphicsProjectGroup10/texture/healthy.bmp";
char bestchoicePath[] = "D:/ComputerGraphicsProjectGroup10/texture/best-choice.bmp";
// Functions //
struct Anmi_state { //if you have image 3 add
	float earth, ery, s, ery2, s2,
		x1, y1, rotat1,
		x2, y2, rotat2,
	

		///case 3
		x1w, y1w, rotat1w,
		x2w, y2w, rotat2w,
		x3w, y3w, rotat3w,
		x4w, y4w, rotat4w,
		x5w, y5w, rotat5w,
		x6w, y6w, rotat6w,
		x7w, y7w, rotat7w,
		x8w, y8w, rotat8w,
		x9w, y9w, rotat9w,
		//case 4
		x1r, y1r, rotat1r,
		x2r, y2r, rotat2r,
		x3r, y3r, rotat3r,
		x4r, y4r, rotat4r,
		x5r, y5r, rotat5r,
		x6r, y6r, rotat6r,
		x7r, y7r, rotat7r,
		x8r, y8r, rotat8r,
		x9r, y9r, rotat9r,
		x10r, y10r, rotat10r,
		x11r, y11r, rotat11r,
		//case5
		x1j, y1j, rotat1j,
		x2j, y2j, rotat2j,
		x3j, y3j, rotat3j;

	//case6
	float  x1t, y1t, rotat1t,
		x2t, y2t, rotat2t,
		x3t, y3t, rotat3t,
		x4t, y4t, rotat4t,
		x5t, y5t, rotat5t;;


	int scen;
} anime;

void action(int n)
{
	n++;
	
	
	// Animate the tranformation
	rotat = 0.1;

	switch (anime.scen) {
	case 1:
		
		break;
	case 2:
		flag0 += 0.1;
		//anime image1
		if (flag0 >= 2.6) {
			if (anime.y1 >= 0.0 && anime.y1 <= 1.0 && flag1 == 1) {//move up the image2
				anime.y1 += 0.5;
				anime.x1 += 0.5;

			}
			else
			{   //stop the image1
				anime.y1 = anime.y1;
				anime.x1 = anime.x1;
				flag1 += 0.1;

			}
			//exit the image1
			if (flag1 >= 3) {

				anime.y1 = 0.0;
				anime.x1 = 0.0;

			}

		}

		//anime image2
		if (flag1 > 3) {
			if (anime.y2 >= 0.0 && anime.y2 <= 1.0 && flag2 == 1) {//move up the image2
				anime.y2 += 0.5;
				anime.x2 += 0.5;

			}
			else
			{   //stop the image1
				anime.y2 = anime.y2;
				anime.x2 = anime.x2;
				flag2 += 0.1;

			}
			//exit the image1
			if (flag2 >= 1.9) {

				anime.y2 = 0.0;
				anime.x2 = 0.0;

			}
		}
		//3


		break;

	case 3:
		////wesal 
		//anime earth
		anime.earth += rotat;

		
		if (anime.y1w >= 0.0 && anime.y1w <= 1.0 && flag1w == 1) {//move up the image2
			anime.y1w += 0.55;
			anime.x1w += 0.55;

		}
		else
		{   //stop the image1
			anime.y1w = anime.y1w;
			anime.x1w = anime.x1w;
			flag1w += 0.1;

		}
		//exit the image1
		if (flag1w >=4.5 ) {
			anime.y1w = 0.0;
			anime.x1w = 0.0;

		}

		
		//anime image2
		if (flag1w >= 4.5) {
			if (anime.x2w >= 0.01 && anime.x2w <= 1.3 && flag2w == 1) {//move up the image2
				anime.x2w -= 0.43;
			}
			else
			{ //stop the image2
				anime.x2w = anime.x2w;
				flag2w += 0.1;

			}
			//exit the image2
			if (flag2w >= 4.2) {
				anime.y2w += 0.4;
				anime.rotat2w += 0.4;
			}
		}
		


		//anime image3
		if (flag2w > 4.2) {
			if (anime.x3w >= 0.01 && anime.x3w <= 1.3 && flag3w == 1) {//move up the image2
				anime.x3w -= 0.43;
			}
			else
			{ //stop the image2
				anime.x3w = anime.x3w;
				flag3w += 0.1;

			}
			//exit the image2
			if (flag3w >= 3) {
				anime.y3w += 0.4;
				anime.rotat3w += 0.5;
			}
		}

		//anime image4
		if (flag3w >= 3) {
			if (anime.x4w >= -1.3 && anime.x4w < -0.01 && flag4w == 1) {//move up the image2
				anime.x4w += 0.43;
			}
			else
			{ //stop the image4
				anime.x4w = anime.x4w;
				flag4w += 0.01;

			}
			//exit the image4
			if (flag4w > 1.1) {
				anime.x4w -= 0.5;
				//anime.rotat4w += 0.5;
			}
		}

		//anime imge 5
		if (flag4w > 1.1) {
			if (anime.x5w >= 0.01 && anime.x5w < 1.3 && flag5w == 1) {//move up the image1
				anime.x5w -= 0.43;
			}
			else
			{ //stop the image5
				anime.x5w = anime.x5w;
				flag5w += 0.1;
			}

			//exit the image4
			if (flag5w > 1.5) {
				anime.x5w -= 0.5;
				//anime.rotat5w += 0.5;
			}
		}

		//6
		if (flag5w > 1.5) {

			if (anime.x6w >= 0.01 && anime.x6w < 1.3 && flag6w == 1) {//move up the image2
				anime.x6w -= 0.43;
			}
			else
			{ //stop the image6
				anime.x6w = anime.x6w;
				flag6w += 0.1;

			}

			//exit the image4
			if (flag6w >= 1.5) {
				anime.x6w -= 0.5;
				//anime.rotat4w += 0.5;
			}

		}   

		//7
		if (flag6w >= 1.5) {
		
			if (anime.y7w >= 0.0 && anime.y7w <= 1.0 && flag7w == 1) {//move up the image2
				anime.y7w += 0.55;
				anime.x7w += 0.55;

			}
			else
			{   //stop the image1
				anime.y7w = anime.y7w;
				anime.x7w = anime.x7w;
				flag7w += 0.1;

			}
			//exit the image1
			if (flag7w >= 2) {
				anime.y7w = 0.0;
				anime.x7w = 0.0;

			}
			

		}
		//8
		if (flag7w >= 2) {

			if (anime.x8w >= 0.01 && anime.x8w <= 1.3 && flag8w == 1) {//move up the image2
				anime.x8w -= 0.43;
			}
			else
			{ //stop the image2
				anime.x8w = anime.x8w;
				flag8w += 0.1;

			}
			//exit the image2
			if (flag8w >= 1.9) {
				anime.y8w += 0.5;
				anime.rotat8w += 0.4;
			}
		}
		
		//9
		if (flag8w >= 1.9) {

			if (anime.y9w >= 0.0 && anime.y9w <= 1.0 && flag9w == 1) {//move up the image2
				anime.y9w += 0.55;
				anime.x9w += 0.55;

			}
			else
			{   //stop the image1
				anime.y9w = anime.y9w;
				anime.x9w = anime.x9w;
				flag9w += 0.1;

			}
			
		}

		break;
		case 4:
			//anime earth
			anime.earth += rotat;
			
			if (anime.y1r >= 0.0 && anime.y1r<= 1.0 && flag1r == 1) {//move up the image2
				anime.y1r += 0.33;
				anime.x1r += 0.33;

			}
			else
			{   //stop the image1
				anime.y1r = anime.y1r;
				anime.x1r = anime.x1r;
				flag1r += 0.1;

			}
			//exit the image1
			if (flag1r >= 2.9) {
				anime.y1r = 0.0;
				anime.x1r = 0.0;

			}	
			
			//2&3
			if (flag1r >= 2.9) {
				//anime image2
				if (anime.y2r >= -0.7 && anime.y2r <= 0.2 && flag2r == 1) {//move up the image2
					anime.y2r += 0.2;
				}
				else
				{ //stop the image2
					anime.y2r = anime.y2r;
					flag2r += 0.1;

				}
				//exit the image2
				if (flag2r > 3.7) {
					anime.x2r += 0.5;
					anime.rotat2r += 0.1;
				}

				//anime image3
				if (anime.y3r >= -0.7 && anime.y3r <= 0.2 && flag3r == 1) {//move up the image1
					anime.y3r += 0.2;
				}
				else
				{ //stop the image1
					anime.y3r = anime.y3r;
					flag3r += 0.1;

				}
				//exit the image1
				if (flag3r > 3.7) {
					anime.x3r -= 0.5;
					anime.rotat3r += 0.1;
				}
			}
			
		
			//anime image 4 5 6
			if (flag3r > 3.7) {

				//anime image4
				if (anime.y4r >= -0.7 && anime.y4r < 0.2 && flag4r == 1) {//move up the image4
					anime.y4r += 0.2;
				}
				else
				{ //stop the image4
					anime.y4r = anime.y4r;
					flag4r += 0.1;
				}

				if (anime.y5r >= -0.7 && anime.y5r < 0.2 && flag5r == 1) {//move up the image5
					anime.y5r += 0.2;
				}
				else
				{ //stop the image5
					anime.y5r = anime.y5r;
					flag5r += 0.1;
				}

				if (anime.y6r >= -0.7 && anime.y6r < 0.2 && flag6r == 1) {//move up the image6
					anime.y6r += 0.2;
				}
				else
				{ //stop the image6
					anime.y6r = anime.y6r;
					flag6r += 0.1;

				}
			
				//exit the image4
				if (flag4r > 2.9) {
					anime.x4r -= 0.5;
					anime.rotat4r += 0.1;
				}
				//exit the image5
				if (flag5r >2.9) {
					anime.x5r -= 0.5;
					anime.rotat5r += 0.1;
				}
				//exit the image6
				if (flag6r > 2.9) {
					anime.x6r -= 0.5;
					anime.rotat6r += 0.1;
				}
			}
			
			
			//anime image7
			if (flag6r > 3) {
				if (anime.y7r >= 0.0 && anime.y7r < 1.0 && flag7r == 1) {//move up the image7
					anime.y7r += 0.33;
					anime.x7r += 0.33;
				}
				else
				{ //stop the image7
					anime.y7r = anime.y7r;
					anime.x7r = anime.x7r;
					flag7r += 0.1;

				}
				//exit the image7
				if (flag7r > 2.2) {
					anime.x7r = 0.0;
					anime.x7r = 0.0;
				}
			}
			
			//anime image8
			if (flag7r > 2.2) {
				//8
				if (anime.y8r >= -0.7 && anime.y8r < 0.2 && flag8r == 1) {//move up the image7
					anime.y8r += 0.2;
				}
				else
				{ //stop the image7
					anime.y8r = anime.y8r;
					flag8r += 0.1;

				}
				//exit the image7
				if (flag8r > 3.5) {
					anime.x8r += 0.5;
					anime.rotat8r += 0.1;
				}

				//10
				if (anime.y10r >= -0.7 && anime.y10r < 0.2 && flag10r == 1) {//move up the image7
					anime.y10r += 0.2;
				}
				else
				{ //stop the image7
					anime.y10r = anime.y10r;
					flag10r += 0.1;

				}
				//exit the image7
				if (flag10r > 3.5) {
					anime.x10r -= 0.5;
					anime.rotat10r += 0.1;
				}
			}

			if(flag10r>3.5){
		         //11
				if (anime.y11r >= -0.7 && anime.y11r < 0.2 && flag11r == 1) {//move up the image7
					anime.y11r += 0.2;
				}
				else
				{ //stop the image7
					anime.y11r = anime.y11r;
					flag11r += 0.01;

				}
			}

			break;


		case 5://jumanah
			//anime earth
			anime.earth += rotat;
			//anime image1

			if (anime.y1j >= 0.0 && anime.y1j <= 1.0 && flag1j == 1) {//move up the image2
				anime.y1j += 0.22;
				anime.x1j += 0.22;

			}
			else
			{   //stop the image1
				anime.y1j = anime.y1j;
				anime.x1j = anime.x1j;
				flag1j += 0.1;

			}
			//exit the image1
			if (flag1j >= 3.6) {
				anime.y1j = 0.0;
				anime.x1j = 0.0;

			}
			

			//anime image2
			if (flag1j > 3.6) {
				if (anime.y2j >= -0.7 && anime.y2j < 0.05 && flag2j == 1) {//move up the image2
					anime.y2j += 0.2;
				}
				else
				{ //stop the image2
					anime.y2j = anime.y2j;
					flag2j += 0.1;

				}

				if (anime.y3j >= 0.4 && anime.y3j <= 1.3 && flag3j == 1) {//move up the image2
					anime.y3j -= 0.2;
				}
				else
				{ //stop the image2
					anime.y3j = anime.y3j;
					flag3j += 0.1;

				}
				
			}

			break;


		case 6:
			//anime earth
			anime.earth += rotat;
			//anime image1
			if (anime.y1t >= 0.0 && anime.y1t < 1.0 && flag1t == 1) {//move up the image1
				anime.y1t += 0.2299;
				anime.x1t += 0.2299;
			}
			else
			{ //stop the image1
				anime.y1t = anime.y1t;
				anime.x1t = anime.x1t;
				flag1t += 0.1;

			}
			//exit the image1
			if (flag1t >= 2.6) {
				anime.y1t = 0.0;
				anime.x1t = 0.0;

			}

			//anime image2
			if (flag1t > 2.6) {
				if (anime.y2t >= 0.0 && anime.y2t < 1.0 && flag2t == 1) {//move up the image2
					anime.y2t += 0.2299;
					anime.x2t += 0.2299;
				}
				else
				{ //stop the image2
					anime.y2t = anime.y2t;
					anime.x2t = anime.x2t;
					flag2t += 0.1;

				}
				//exit the image2
				if (flag2t >= 3.8) {
					anime.y2t = 0.0;
					anime.x2t = 0.0;
					
				}
			}

			//3
			if (flag2t > 3.8) {
				if (anime.y3t >= 0.0 && anime.y3t < 1.0 && flag3t == 1) {//move up the image2
					anime.y3t += 0.2299;
					anime.x3t += 0.2299;
				}
				else
				{ //stop the image2
					anime.y3t = anime.y3t;
					anime.x3t = anime.x3t;
					flag3t += 0.1;

				}
				//exit the image2
				if (flag3t >= 1.9) {
					anime.x3t = 0.0;
					anime.y3t = 0.0;
				}
			}cout << "flag8w=" << flag4t << endl;
			///////////////////////////////////////
			if (flag3t > 1.9) {
				if (anime.y4t >= 0.0 && anime.y4t < 1.0 && flag4t == 1) {//move up the image2
					anime.y4t += 0.2299;
					anime.x4t += 0.2299;
				}
				else
				{ //stop the image2
					anime.y4t = anime.y4t;
					anime.x4t = anime.x4t;
					flag4t += 0.1;

				}
				//exit the image2
				if (flag4t >= 2) {
					anime.x4t = 0.0;
					anime.y4t = 0.0;
					
				}
			}
			if (flag4t > 2) {
				if (anime.y5t >= 0.0 && anime.y5t < 1.0 && flag5t == 1) {//move up the image2
					anime.y5t += 0.2299;
					anime.x5t += 0.2299;
				}
				else
				{ //stop the image2
					anime.y5t = anime.y5t;
					anime.x5t = anime.x5t;
					flag5t += 0.1;

				}
				
			}

		
			


	default:
		break;
	}
	glutTimerFunc(150,action , n);
	glutPostRedisplay();
}
//http://stackoverflow.com/questions/12518111/how-to-load-a-bmp-on-glut-to-use-it-as-a-texture
GLuint LoadTexture(const char* filename, int width, int height)///فنكشن نناديها بعدين
{
	GLuint texture;
	unsigned char* data;
	FILE* file;
	file = fopen(filename, "rb");
	if (file == NULL)
	{
		cout << "Unable to open the image file" << endl << "Program will exit :(" << endl;
		exit(0);
		return 0;
	}
	data = (unsigned char*)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);
	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}

	glGenTextures(1, &texture); //generate the texture with the loaded data 
	glBindTexture(GL_TEXTURE_2D, texture); //bind the texture to it's array


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//GL_MODULATE اذا بدمج لون الشكل مع الصورة
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	/////////////////////////////////////////

	free(data); //free the texture array متعلق بالايرو

	if (glGetError() != GL_NO_ERROR)
		printf("GLError in genTexture()\n");

	return texture; //return whether it was successfull
}
static void playEarth(void)
{
	switch (anime.scen) {
	case 1:
		//anime earth
		anime.earth += rotat;
		break;

	case 2:
		if (anime.ery >= 0.0 && anime.ery < 1.2 && flag00 == 1) {//move up the image2
			anime.ery += 0.0009;
			anime.s += 0.0005;
			/*anime.ery += 0.0009;
			anime.s += 0.0005;*/
			anime.earth += rotat;
			//anime.erx += 0.001;

		}
		else
		{   //stop the image1
			anime.ery = anime.ery;
			anime.s = anime.s;
			//anime.x1 = anime.x1;


		}
		anime.earth += rotat;
		break;

	case 3:
		anime.earth += rotat;
	break;

	case 4:
		anime.earth += rotat;
		break;

	case 5:
		anime.earth += rotat;
		break;

	case 6:
		anime.earth += rotat;
		break;

	case 7:
		if (flag02 == 1) {
			anime.ery2 -= 0.001;
			anime.s2 -= 0.0005;
			/*anime.ery2 -= 0.001;
			anime.s2 -= 0.0005;*/
			anime.earth += rotat;
			//anime.erx += 0.001;
		}
		if (anime.ery2 <= 0.0) {
			//stop the image1
			anime.ery2 = anime.ery2;
			anime.s2 = anime.s2;
			flag02 += 0.01;
		}
		anime.earth += rotat;
		break;
	}
	glutPostRedisplay();
}

void init() {
	
	//defult value
	anime.scen = -1;
	//------- Texture ---------
	earth_image = LoadTexture(image1Path, 1300, 635);//نحدد الطول والعرض والباث
	if (earth_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << earth_image << endl;
	///////////case2////////
	choice_img = LoadTexture(choicePath, 512, 512); //نحدد الباث والطول والعرض
	if (choice_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << choice_img << endl;

	question_img = LoadTexture(questionPath, 512, 512); //نحدد الباث والطول والعرض
	if (question_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << question_img << endl;


	////case 3////////////////////////////////////////////////////
	
	threeR_image = LoadTexture(threeRPath, 703, 477);
	if (threeR_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << threeR_image << endl;

	garbage_img = LoadTexture(garbagePath, 512, 512);
	if (garbage_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << threeR_image << endl;

	off_image = LoadTexture(offPath, 512, 512);
	if (threeR_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << off_image << endl;

	publictrans_image = LoadTexture(publictransPath, 512, 512);
	if (threeR_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << publictrans_image << endl;

	walk_image = LoadTexture(walkPath, 512, 512);
	if (threeR_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << walk_image << endl;

	bike_image = LoadTexture(bikePath, 512, 512);
	if (threeR_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << bike_image << endl;

	pollution_img = LoadTexture(pollutionPath, 512, 512);
	if (threeR_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << pollution_img << endl;

	energyrecours_image = LoadTexture(energyrecoursPath,512, 512);
	if (threeR_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << energyrecours_image << endl;


	think_img = LoadTexture(thinkPath, 512, 512); //نحدد الباث والطول والعرض

	if (think_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << think_img << endl;

	///////////case 4 //////////

	idea_img = LoadTexture(ideaPath, 512, 512); //نحدد الباث والطول والعرض
	if (idea_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << idea_img << endl;

	pbag_img = LoadTexture(pbagPath, 512, 512); //نحدد الباث والطول والعرض

	if (pbag_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << pbag_img << endl;

	water_imge = LoadTexture(waterPath, 512, 512); //نحدد الباث والطول والعرض
	if (ecobag_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << water_imge << endl;

	ocean_image = LoadTexture(oceanPath, 512, 512); //نحدد الباث والطول والعرض
	if (ecobag_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << ocean_image << endl;

	trash1_img = LoadTexture(trash1Path, 512, 512); //نحدد الباث والطول والعرض
	if (trash1_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << trash1_img << endl;

	trash2_img = LoadTexture(trash2Path, 512, 512); //نحدد الباث والطول والعرض
	if (trash1_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << trash2_img << endl;

	noplastic_img = LoadTexture(noplasticPath, 512, 512); //نحدد الباث والطول والعرض
	if (noplastic_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << noplastic_img << endl;

	ecobag_image = LoadTexture(ecobagPath, 512, 512); //نحدد الباث والطول والعرض
	if (ecobag_image == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << ecobag_image << endl;

	reusee_img = LoadTexture(reuseePath, 512, 512);
	if (reusee_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << reusee_img << endl;

	rewater_img = LoadTexture(rewaterPath, 512, 512);
	if (rewater_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << rewater_img << endl;

	jarj_img = LoadTexture(jarPath, 512, 512);
	if (jarj_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << jarj_img << endl;

	/////case 5///////////////////////////////////////////////////////////////////

	factory_img = LoadTexture(factoryPath, 512, 512); //نحدد الباث والطول والعرض
	if (factory_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << factory_img << endl;

	organicj_img = LoadTexture(organicPath, 512, 512); //نحدد الباث والطول والعرض
	if (organicj_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << organicj_img << endl;

	compostj_img = LoadTexture(composotPath, 512, 512); //نحدد الباث والطول والعرض
	if (compostj_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << compostj_img << endl;

	/////////// case 6//
	zerowaste_img = LoadTexture(zerowastePath, 512, 512);
	if (zerowaste_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << zerowaste_img << endl;

	check_img = LoadTexture(checkPath, 512, 512);
	if (check_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << check_img << endl;

	refuse_img = LoadTexture(refusePath, 512, 512);
	if (refuse_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << refuse_img << endl;

	healthy_img = LoadTexture(healthyPath, 512, 512);
	if (healthy_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << healthy_img << endl;

	bestchoice_img = LoadTexture(bestchoicePath, 512, 512);
	if (bestchoice_img == -1)
	{
		cout << "Error in loading the texture" << endl;
	}
	else
		cout << "The texture value is: " << bestchoice_img << endl;

	/// lighttt
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

 	 


	glClearColor(0.82f, 0.94f, 0.75f, 0.0f); // Set background color 
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1, 1, -1, 1);



	
	
}
void reshape(GLint new_width, GLint new_hight)
{
	glViewport(0, 0, new_width, new_hight);
	win_width = new_width;
	win_hight = new_hight;
}

//Alaa
//add text
void text(float x, float y, float r, float g, float b, char* string)
{
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	int len, i;
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}
//alaa
void earth() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, earth_image);
	glEnable(GL_DEPTH_TEST);
	glColor3f(1, 1, 1);
	GLUquadric* qobj = gluNewQuadric();
	gluQuadricTexture(qobj, GL_TRUE);
	gluSphere(qobj, 0.6, 200, 200);
	gluDeleteQuadric(qobj);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	

}

void squareTexure(GLuint image1) {
	/* front => ABCD yellow */
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image1); //ربط
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 1);
	glVertex3fv(vertA);
	glTexCoord2f(1, 1);
	glVertex3fv(vertB);
	glTexCoord2f(1, 0);
	glVertex3fv(vertC);
	glTexCoord2f(0, 0);
	glVertex3fv(vertD);
	glDisable(GL_TEXTURE_2D);
	glEnd();
}


void square2Texure(GLuint image) {
	/* front => ABCD yellow */
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image); //ربط
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 1);
	glVertex3fv(vert2A);
	glTexCoord2f(1, 1);
	glVertex3fv(vert2B);
	glTexCoord2f(1, 0);
	glVertex3fv(vert2C);
	glTexCoord2f(0, 0);
	glVertex3fv(vert2D);
	glDisable(GL_TEXTURE_2D);
	glEnd();
}

void square3Texure(GLuint image3) {
	/* front => ABCD yellow */
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image3); //ربط
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 1);
	glVertex3fv(vert3A);
	glTexCoord2f(1, 1);
	glVertex3fv(vert3B);
	glTexCoord2f(1, 0);
	glVertex3fv(vert3C);
	glTexCoord2f(0, 0);
	glVertex3fv(vert3D);
	glDisable(GL_TEXTURE_2D);
	glEnd();
}
////keyboard event handler
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '1':
		//go to scen1
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/1.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/1.wav"), NULL, SND_ASYNC | SND_FILENAME);
		//PlaySound("D:/ComputerGraphicsProjectGroup10/texture/1.wav", NULL, SND_ASYNC | SND_FILENAME);
		//PlaySound("music.wav", NULL, SND_ASYNC | SND_FILENAME);
		anime.scen = 1;
		
		break;
	case '2':
		//go to scen1
		
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/2.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/2.wav"), NULL, SND_ASYNC | SND_FILENAME);
		anime.scen = 2;
		anime.ery = 0.0;
		anime.s = 1.0;
		anime.x1 = 0.0;
		anime.y1 = 0.0;
		anime.rotat1 = 0;
		flag1 = 1;
		flag0 = 0;
		flag00 = 1;

		//variable image2
		anime.x2 = 0.0;
		anime.y2 = 0.0;
		anime.rotat2 = 0;
		flag2 = 1;


		break;



	case '3'://go to scen3
		
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/3.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/3.wav"), NULL, SND_ASYNC | SND_FILENAME);
		anime.scen = 3;
		//variable image1
		anime.x1w = 0.0;
		anime.y1w = 0.0;
		anime.rotat1w = 0;
		flag1w = 1;

		

		//variable image2
		anime.x2w = 1.3;
		anime.y2w = 0.335663;
		anime.rotat2w = 0;
		flag2w = 1;


		//variable image3
		anime.x3w = 1.3;
		anime.y3w = 0.335663;
		anime.rotat3w = 0;
		flag3w = 1;

		//variable image4
		anime.x4w = -1.3;
		anime.y4w = 0.335663;
		anime.rotat4w = 0;
		flag4w = 1;

		//variable image5
		anime.x5w = 1.3;
		anime.y5w = 0.335663;
		anime.rotat5w = 0;
		flag5w = 1;

		//variable image6
		anime.x6w = 1.3;
		anime.y6w = 0.335663;
		anime.rotat6w = 0;
		flag6w = 1;

		//variable image7
		anime.x7w = 0.0;
		anime.y7w = 0.0;
		anime.rotat7w = 0;
		flag7w = 1;

		//variable image8
		anime.x8w = 1.3;
		anime.y8w = 0.335663;
		anime.rotat8w = 0;
		flag8w = 1;

		//variable image9
		anime.x9w = 0.0;
		anime.y9w = 0.0;
		anime.rotat9w = 0;
		flag9w = 1;


		//go to scen2
		
		break;

	case '4'://go to scen3
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/4.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/4.wav"), NULL, SND_ASYNC | SND_FILENAME);
		anime.scen = 4;//go to scen4

		anime.x1r = 0.0;
		anime.y1r = 0.05;
		anime.rotat1r = 0;
		flag1r = 1;


		//variable image2
		anime.x2r = 0.4;
		anime.y2r = -0.7;
		anime.rotat2r = 0;
		flag2r = 1;

		//variable image3
		anime.x3r = -0.4;
		anime.y3r = -0.7;
		anime.rotat3r = 0;
		flag3r = 1;
		///////////////////////////
		//variable image4
		anime.x4r = 0;
		anime.y4r = -0.7;
		anime.rotat4r = 0;
		flag4r = 1;

		//variable image5
		anime.x5r = 0.5;
		anime.y5r = -0.7;
		anime.rotat5r = 0;
		flag5r = 1;

		//variable image6
		anime.x6r = -0.5;
		anime.y6r = -0.7;
		anime.rotat6r = 0;
		flag6r = 1;

		//variable image7
		anime.x7r = 0.0;
		anime.y7r = 0.05;
		anime.rotat7r = 0;
		flag7r = 1;
///////////////
		//variable image8
		anime.x8r = -0.4;
		anime.y8r = -0.7;
		anime.rotat8r = 0;
		flag8r = 1;

		//variable image10
		anime.x10r = 0.4;
		anime.y10r = -0.7;
		anime.rotat10r = 0;
		flag10r = 1;
//////
		//variable image8
		anime.x11r = 0.0;
		anime.y11r = -0.7;
		anime.rotat11r = 0;
		flag11r = 1;

		
		break;

	case '5'://go to scen5
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/5.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/5.wav"), NULL, SND_ASYNC | SND_FILENAME);
		anime.scen = 5;//go to scen5
		//variable image1
		anime.x1j = 0;
		anime.y1j = 0;
		anime.rotat1j = 0;
		flag1j = 1;


		//variable image2
		anime.x2j = 0.2;
		anime.y2j = -0.7;
		anime.rotat2j = 0;
		flag2j = 1;


		//variable image3
		anime.x3j = -0.2;
		anime.y3j = 1.3;
		anime.rotat3j = 0;
		flag3j = 1;

		
		break;

	case '6'://go to scen5
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/6.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/6.wav"), NULL, SND_ASYNC | SND_FILENAME);
		anime.scen = 6;//go to scen6
		//variable image1
		anime.x1t = 0;
		anime.y1t = 0;
		anime.rotat1t = 0;
		flag1t = 1;


		//variable image2
		anime.x2t = 0;
		anime.y2t = 0.0;
		anime.rotat2t = 0;
		flag2t = 1;



		//variable image3
		anime.x3t = 0;
		anime.y3t = 0;
		anime.rotat3t = 0;
		flag3t = 1;


		//variable image4
		anime.x4t = 0;
		anime.y4t = 0;
		anime.rotat4t = 0;
		flag4t = 1;


		//variable image5
		anime.x5t = 0;
		anime.y5t = 0;
		anime.rotat5t = 0;
		flag5t = 1;

		
		break;
	case '7'://go to scen7
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/7.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		PlaySound(TEXT("D:/ComputerGraphicsProjectGroup10/7.wav"), NULL, SND_ASYNC | SND_FILENAME);
		anime.scen = 7;

	  anime.ery2 = 1.1;
	  anime.s2 = 1.6;
	  flag01 = 0;
	  flag02 = 1;
	  
      break;
	case '8':

		break;
	case 'n':
		
	case 27:
		exit(0);
		break;

	default:
		fprintf(stderr, "\nKeyboard commands:\n\n"
			"q, <esc> - Quit\n");

		break;
	}
	glutPostRedisplay();
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	//add text
	char string[] = "GO GREEN";
	char string0[] = "LETS START :)!";
	char string1[] = "THE GREEN TEAM";
	char string3[] = "REUSE";
	char string4[] = "REDUSE";
	char string5[] = "RECYCLE";
	char string7[] = "GO GREEN, ";
	char string8[] = "AND SAVE THE EARTH! ";
	char string9[] = "THANK YOU FOR WATCHING :)! ";

	switch (anime.scen)
	{//ALAA
	case 1:
		//add text here
		text(-0.15f, 0.7f, 0, 0.4, 0.1, string);//go green
		//earth
		glRotatef(anime.earth, 0, 1, 0);
		glRotatef(-270, 0, 1, 0);
		glRotatef(-270, 1, 0, 0);
		earth();
		glFlush();



		break;
	case 2:

		//choice_img,
		glPushMatrix();
		glScalef(anime.x1, anime.y1, 1);
		glTranslatef(0.03, 0.069, 0);
		square2Texure(choice_img);//add your texure name here
		glPopMatrix();
		glFlush();


		//image2
		glPushMatrix();
		glScalef(anime.x2, anime.y2, 1);
		glTranslatef(-0.01, 0.2, 0);
		square2Texure(question_img);//add your texure name here
		glPopMatrix();
		glFlush();

		if (flag2 >=1.9) {
			text(-0.20f, 0.35, 0.0, 0.0, 0.0, string0);
		}

		//earth
		glPushMatrix();
		glRotatef(anime.earth, 0, 1, 0);
		glRotatef(-270, 1, 0, 0);
		glTranslatef(0, 0, anime.ery);
		glScalef(anime.s, anime.s, anime.s);
		earth();
		glPopMatrix();
		glFlush();

		break;

	case 3://reduce//wesal
		
	//image1
		glPushMatrix();
		glScalef(anime.x1w, anime.y1w, 1);
		glTranslatef(-0.01, 0.3, 0);
		square3Texure(threeR_image);//add your texure name here
		glPopMatrix();
		glFlush();

		if (flag1w >=4.5 ) {
			text(-0.13, 0.7, 0, 0.4, 0.1, string4);
		}


		//image2
		glPushMatrix();
		glTranslatef(anime.x2w, anime.y2w, 0);
		glRotatef(anime.rotat2w, 0, 0, 1);
		square2Texure(garbage_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image3
		glPushMatrix();
		glTranslatef(anime.x3w, anime.y3w, 0);
		glRotatef(anime.rotat3w, 0, 1, 0);
		square2Texure(off_image);//add your texure name here
		glPopMatrix();
		glFlush();

		//image4
		glPushMatrix();
		glTranslatef(anime.x4w, anime.y4w, 0);
		glRotatef(anime.rotat4w, 0, 0, 1);
		square2Texure(publictrans_image);//add your texure name here
		glPopMatrix();
		glFlush();

		//image5
		glPushMatrix();	
		glTranslatef(anime.x5w, anime.y5w, 0);
		glRotatef(anime.rotat5w, 0, 1, 0);
		square2Texure(walk_image);//add your texure name here
		glPopMatrix();
		glFlush();


		//image6
		glPushMatrix();
		glTranslatef(anime.x6w, anime.y6w, 0);
		glRotatef(anime.rotat6w, 0, 0, 1);
		square2Texure(bike_image);//add your texure name here
		glPopMatrix();
		glFlush();

		//image7
		glPushMatrix();
		glScalef(anime.x7w, anime.y7w, 1);
		glTranslatef(-0.01, 0.335663, 0);
		squareTexure(pollution_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image8
		glTranslatef(anime.x8w, anime.y8w, 0);
		glRotatef(anime.rotat8w, 0, 0, 1);
		squareTexure(energyrecours_image);//add your texure name here
		glPopMatrix();
		glFlush();

		//image9
		glPushMatrix();
		glScalef(anime.x9w, anime.y9w, 1);
		glTranslatef(-0.01, 0.335663, 0);
		square2Texure(think_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//PlaySound(TEXT("MusicName.wav"), NULL, SND_SYNC);
		//earth
		glPushMatrix();
		glRotatef(anime.earth, 0, 1, 0);
		glRotatef(-270, 1, 0, 0);
		glTranslatef(0, 0, 1.1);
		glScalef(1.6, 1.6, 1.6);
		earth();
		glPopMatrix();
		glFlush();
		break;

	case 4://reuse////raghad
		text(-0.13, 0.7, 0, 0.4, 0.1, string3);

		//image1
		glPushMatrix();
		glScalef(anime.x1r, anime.y1r, 1);
		glTranslatef(-0.01, 0.335663, 0);
		squareTexure(idea_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image2
		glPushMatrix();
		glTranslatef(anime.x2r, anime.y2r, 0);
		glRotatef(anime.rotat2r, 0, 0, 1);
		squareTexure(pbag_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image3
		glPushMatrix();
		glTranslatef(anime.x3r, anime.y3r, 0);
		glRotatef(anime.rotat3r, 0, 1, 0); 
		squareTexure(water_imge);//add your texure name here
		glPopMatrix();
		glFlush();

		//image4
		glPushMatrix();
		glTranslatef(anime.x4r, anime.y4r, 0);
		glRotatef(anime.rotat4r, 1, 0, 0);

		square2Texure(ocean_image);//add your texure name here
		glPopMatrix();
		glFlush();

		//image5
		glPushMatrix();
		glTranslatef(anime.x5r, anime.y5r, 0);
		glRotatef(anime.rotat5r, 1, 0, 0);
		square2Texure(trash1_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image6
		glPushMatrix();
		glTranslatef(anime.x6r, anime.y6r, 0);
		glRotatef(anime.rotat6r, 1, 0, 0);
		square2Texure(trash2_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image7
		glPushMatrix();
		glScalef(anime.x7r, anime.y7r, 1);
		glTranslatef(-0.01, 0.335663, 0);
		squareTexure(noplastic_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image8
		glPushMatrix();
		glTranslatef(anime.x8r, anime.y8r, 0);
		glRotatef(anime.rotat8r, 1, 0, 0);
		squareTexure(ecobag_image);//add your texure name here
		glPopMatrix();
		glFlush();


		//image10
		glPushMatrix();
		glTranslatef(anime.x10r, anime.y10r, 0);
		glRotatef(anime.rotat10r, 1, 0, 0);
		squareTexure(rewater_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image11
		glPushMatrix();
		glTranslatef(anime.x11r, anime.y11r, 0);
		glRotatef(anime.rotat11r, 0, 1, 0);
		squareTexure(jarj_img);//add your texure name here
		glPopMatrix();
		glFlush();

		
		//earth
		glPushMatrix();
		glRotatef(anime.earth, 0, 1, 0);
		glRotatef(-270, 1, 0, 0);
		glTranslatef(0, 0, 1.1);
		glScalef(1.6, 1.6, 1.6);
		earth();
		glPopMatrix();
		glFlush();
		break;

	case 5:
		//JUMANAH
		//add text her
		text(-0.18, 0.7, 0, 0.4, 0.1, string5);
		//image1
		glPushMatrix();
		glScalef(anime.x1j, anime.y1j, 1);
		glTranslatef(-0.01, 0.335663, 0);
		squareTexure(factory_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image2
		glPushMatrix();
		glTranslatef(anime.x2j, anime.y2j, 0);
		glRotatef(anime.rotat2j, 0, 0, 1);
		square2Texure(organicj_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image3
		glPushMatrix();
		glTranslatef(anime.x3j, anime.y3j, 0);
		glRotatef(anime.rotat3j, 0, 1, 0);
		square2Texure(compostj_img);//add your texure name here
		glPopMatrix();
		glFlush();


		//earth
		glPushMatrix();
		glRotatef(anime.earth, 0, 1, 0);
		glRotatef(-270, 1, 0, 0);
		glTranslatef(0, 0, 1.1);
		glScalef(1.6, 1.6, 1.6);
		earth();
		glPopMatrix();
		glFlush();
		break;


	case 6://TALLA
		//add text her
		glPushMatrix();
		glScalef(anime.x1t, anime.y1t, 0);
		glTranslatef(0.0, 0.335663, 0);
		squareTexure(zerowaste_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image2
		glPushMatrix();
		glScalef(anime.x2t, anime.y2t, 0);
		glTranslatef(0.0, 0.335663, 0);
		squareTexure(check_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image3
		glPushMatrix();
		glScalef(anime.x3t, anime.y3t, 0);
		glTranslatef(0.0, 0.335663, 0);
		squareTexure(refuse_img);//add your texure name here
		glPopMatrix();
		glFlush();


		//image4
		glPushMatrix();
		glScalef(anime.x4t, anime.y4t, 0);
		glTranslatef(0.0, 0.335663, 0);
		squareTexure(healthy_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//image5
		glPushMatrix();
		glScalef(anime.x5t, anime.y5t, 0);
		glTranslatef(0.0, 0.335663, 0);
		squareTexure(bestchoice_img);//add your texure name here
		glPopMatrix();
		glFlush();

		//earth
		glPushMatrix();
		glRotatef(anime.earth, 0, 1, 0);
		glRotatef(-270, 1, 0, 0);
		glTranslatef(0, 0, 1.1);
		glScalef(1.6, 1.6, 1.6);
		earth();
		glPopMatrix();
		glFlush();
		break;
	case 7:

		//add text here
		text(-0.53f, 0.7f, 0, 0.4, 0.1, string7);//go green
		text(-0.15f, 0.7f, 0, 0.4, 0.1, string8);//go green
		if(flag02 >= 1.1) {
			text(-0.50f, -0.75, 0.0, 0.0, 0.0, string9);
		}
		
		//earth
		glPushMatrix();
		glRotatef(anime.earth, 0, 1, 0);
		glRotatef(-270, 0, 1, 0);
		glRotatef(-270, 1, 0, 0);
		glTranslatef(0, 0, anime.ery2);
		glScalef(anime.s2, anime.s2, anime.s2);
		earth();
		glPopMatrix();
		glFlush();

		
		break;
	
	default:
		text(-0.15, 0.07, 0, 0, 0, string);//GO green
		text(-0.29, -0.08, 0, 0, 0, string1);//the green team
		break;
	}
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}



int main(int argc, char** argv)
{

	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // Specify the display Mode ñ RGB, RGBA or color // Index, single or double Buffer
	glutInitWindowSize(700, 700); // Set the window's initial width & height
	glutInitWindowPosition(250, 50); // Position the window's initial top-left corner
	glutCreateWindow("THE GREEN TEAM PROJECT"); // Create a window with the given title
	init();
	
	times = 1;



	glutTimerFunc(150, action, times);
	glutIdleFunc(playEarth);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	//glutIdleFunc(action);
	glutKeyboardFunc(keyboard);
	
	glutMainLoop();
	return 0;
}
