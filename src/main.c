/*
 * This code was created by Jeff Molofee '99 
 * (ported to Linux/GLX by Mihael Vrbanec '00)
 *
 * If you've found this code useful, please let me know.
 *
 * Visit Jeff at http://nehe.gamedev.net/
 * 
 * or for port-specific comments, questions, bugreports etc. 
 * email to Mihael.Vrbanec@stud.uni-karlsruhe.de
 */
 
#include <stdio.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <X11/extensions/xf86vmode.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "ply.h"
#include "paul_ply.h"
#include "point.h"
#include "triangle.h"
#include "rigidobject.h"
#include <dirent.h>

/* stuff about our window grouped together */
typedef struct {
    Display *dpy;
    int screen;
    Window win;
    GLXContext ctx;
    XSetWindowAttributes attr;
    Bool fs;
    Bool doubleBuffered;
    XF86VidModeModeInfo deskMode;
    int x, y;
    unsigned int width, height;
    unsigned int depth; 
      
} GLWindow;

/* attributes for a single buffered visual in RGBA format with at least
 * 4 bits per color and a 16 bit depth buffer */
static int attrListSgl[] = {GLX_RGBA, GLX_RED_SIZE, 4, 
    GLX_GREEN_SIZE, 4, 
    GLX_BLUE_SIZE, 4, 
    GLX_DEPTH_SIZE, 16,
    None};

/* attributes for a double buffered visual in RGBA format with at least 
 * 4 bits per color and a 16 bit depth buffer */
static int attrListDbl[] = { GLX_RGBA, GLX_DOUBLEBUFFER, 
    GLX_RED_SIZE, 4, 
    GLX_GREEN_SIZE, 4, 
    GLX_BLUE_SIZE, 4, 
    GLX_DEPTH_SIZE, 16,
    None };

GLWindow GLWin;
GLfloat rotTri, rotQuad;

/* function called when our window is resized (should only happen in window mode) */
void resizeGLScene(unsigned int width, unsigned int height)
{
    if (height == 0)    /* Prevent A Divide By Zero If The Window Is Too Small */
        height = 1;
    glViewport(0, 0, width, height);    /* Reset The Current Viewport And Perspective Transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

/* general OpenGL initialization function */
int initGL(GLvoid)
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    /* we use resizeGLScene once to set up our initial perspective */
    resizeGLScene(GLWin.width, GLWin.height);
    /* Reset the rotation angles of our objects */
    rotTri = 0;
    rotQuad = 0;
    return True;
}

GLfloat X=0;
GLfloat Y=0;
GLfloat Z=0;

void initLight(){

	/* Définition des différents paramètres */

	GLfloat mat_amb_diff[]={ 0.7,0.7,0.7,1.0 };
	GLfloat light_ambient[]= { 0.2, 0.2, 0.2,1.0 };
	GLfloat light_diffuse[]= { 0.0, 0.0, 1.0,1.0 };
	GLfloat light_specular[]= { 1.0, 1.0, 1.0,1.0 };
	GLfloat light_position[]= { 0.0, 0.0, 0.0,0.0 };
	GLfloat mat_emission[]= { 1.0,0.0,1.0,0.0 };
	GLfloat low_shininess[]={128.0};

	/* Positionnement de la lumière */ 

	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0, GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glEnable(GL_LIGHT0);
	
	/* Réfléxion de la lumière sur l'objet */
	
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,light_ambient);
	glMaterialfv(GL_FRONT,GL_SPECULAR,light_specular);
	glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,low_shininess);
	
}	
	
Tpoint* Update_Normale(Tpoint* normale)
	{
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();glRotatef(-rotTri, 0.0f, -1.0f, 0.0f);
		glTranslatef(0.0f, +0.1f, +0.2f);
		
		glPushMatrix();
		return normale;
	}

/* Here goes our drawing code */
int drawGLScene(Tpoint* compute_normals, Trigidobject* object){

	int i=0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(X,Y,Z);
	glTranslatef(0.0f, -0.1f, -0.2f); /* Part de 0.0.0 et recule de 1.5 sur les x, ne bouge pas les y et recule de 6 sur les z */
	glRotatef(rotTri, 0.0f, 1.0f, 0.0f);/* Effectue rotation 0.15f */
	glPushMatrix();  
	    
	//initLight();  

	
for(i=0; i<object->nb_triangles; i++){  

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_NORMALIZE);
	//compute_normals=Update_Normale(compute_normals);
	
	glNormal3f(compute_normals->x,compute_normals->y,compute_normals->z);
	
	if(compute_normals->z > 0)
	{
	
	
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(object->tab_points[object->tab_triangles[i].points[0]].x,
		object->tab_points[object->tab_triangles[i].points[0]].y,
		object->tab_points[object->tab_triangles[i].points[0]].z);
		
	glVertex3f(object->tab_points[object->tab_triangles[i].points[0]].x+compute_normals->x+0.002,
		object->tab_points[object->tab_triangles[i].points[0]].y+compute_normals->y+0.002,
		object->tab_points[object->tab_triangles[i].points[0]].z+compute_normals->z+0.002);
		glEnd();
		
		
	glBegin(GL_TRIANGLES);
		 
	//glColor3f(1.0f,0.0f,1.0f);
	
	
			// Vertex 1
	glVertex3f(object->tab_points[object->tab_triangles[i].points[0]].x,
		object->tab_points[object->tab_triangles[i].points[0]].y,
		object->tab_points[object->tab_triangles[i].points[0]].z);

		// Vertex 2
	glVertex3f(object->tab_points[object->tab_triangles[i].points[1]].x,
			object->tab_points[object->tab_triangles[i].points[1]].y,
			object->tab_points[object->tab_triangles[i].points[1]].z);
			
		// Vertex 3
		glVertex3f(object->tab_points[object->tab_triangles[i].points[2]].x,
			object->tab_points[object->tab_triangles[i].points[2]].y,
			object->tab_points[object->tab_triangles[i].points[2]].z);
		
		glEnd();
		
	}
	
/*
	glBegin(GL_LINES);
	glColor3f(1.0f,1.0f,1.0f);
	glEnable(GL_NORMALIZE);
	compute_normals=Normal_Calcul(object, i);

	
	glNormal3f(compute_normals->x,compute_normals->y,compute_normals->z);
	if(compute_normals->z > 0)
	{
	glVertex3f(object->tab_points[object->tab_triangles[i].points[0]].x,
		object->tab_points[object->tab_triangles[i].points[0]].y,
		object->tab_points[object->tab_triangles[i].points[0]].z);
	glVertex3f(object->tab_points[object->tab_triangles[i].points[0]].x+compute_normals->x+0.002,
		object->tab_points[object->tab_triangles[i].points[0]].y+compute_normals->y+0.002,
		object->tab_points[object->tab_triangles[i].points[0]].z+compute_normals->z+0.002);
	}
	
	
	glEnd();*/
	}
	
	
  					

    if (GLWin.doubleBuffered)
    {
        glXSwapBuffers(GLWin.dpy, GLWin.win);
    }
    return True;    
}

/* function to release/destroy our resources and restoring the old desktop */
GLvoid killGLWindow(GLvoid)
{
    if (GLWin.ctx)
    {
        if (!glXMakeCurrent(GLWin.dpy, None, NULL))
        {
            printf("Could not release drawing context.\n");
        }
        glXDestroyContext(GLWin.dpy, GLWin.ctx);
        GLWin.ctx = NULL;
    }
    /* switch back to original desktop resolution if we were in fs */
    if (GLWin.fs)
    {
        XF86VidModeSwitchToMode(GLWin.dpy, GLWin.screen, &GLWin.deskMode);
        XF86VidModeSetViewPort(GLWin.dpy, GLWin.screen, 0, 0);
    }
    XCloseDisplay(GLWin.dpy);
}

/* this function creates our window and sets it up properly */
/* FIXME: bits is currently unused */
Bool createGLWindow(char* title, int width, int height, int bits,
                    Bool fullscreenflag)
{
    XVisualInfo *vi;
    Colormap cmap;
    int dpyWidth, dpyHeight;
    int i;
    int glxMajorVersion, glxMinorVersion;
    int vidModeMajorVersion, vidModeMinorVersion;
    XF86VidModeModeInfo **modes;
    int modeNum;
    int bestMode;
    Atom wmDelete;
    Window winDummy;
    unsigned int borderDummy;
    
    GLWin.fs = fullscreenflag;
    /* set best mode to current */
    bestMode = 0;
    /* get a connection */
    GLWin.dpy = XOpenDisplay(0);
    GLWin.screen = DefaultScreen(GLWin.dpy);
    XF86VidModeQueryVersion(GLWin.dpy, &vidModeMajorVersion,
        &vidModeMinorVersion);
    printf("XF86VidModeExtension-Version %d.%d\n", vidModeMajorVersion,
        vidModeMinorVersion);
    XF86VidModeGetAllModeLines(GLWin.dpy, GLWin.screen, &modeNum, &modes);
    /* save desktop-resolution before switching modes */
    GLWin.deskMode = *modes[0];
    /* look for mode with requested resolution */
    for (i = 0; i < modeNum; i++)
    {
        if ((modes[i]->hdisplay == width) && (modes[i]->vdisplay == height))
        {
            bestMode = i;
        }
    }
    /* get an appropriate visual */
    vi = glXChooseVisual(GLWin.dpy, GLWin.screen, attrListDbl);
    if (vi == NULL)
    {
        vi = glXChooseVisual(GLWin.dpy, GLWin.screen, attrListSgl);
        GLWin.doubleBuffered = False;
        printf("Only Singlebuffered Visual!\n");
    }
    else
    {
        GLWin.doubleBuffered = True;
        printf("Got Doublebuffered Visual!\n");
    }
    glXQueryVersion(GLWin.dpy, &glxMajorVersion, &glxMinorVersion);
    printf("glX-Version %d.%d\n", glxMajorVersion, glxMinorVersion);
    /* create a GLX context */
    GLWin.ctx = glXCreateContext(GLWin.dpy, vi, 0, GL_TRUE);
    /* create a color map */
    cmap = XCreateColormap(GLWin.dpy, RootWindow(GLWin.dpy, vi->screen),
        vi->visual, AllocNone);
    GLWin.attr.colormap = cmap;
    GLWin.attr.border_pixel = 0;

    if (GLWin.fs)
    {
        XF86VidModeSwitchToMode(GLWin.dpy, GLWin.screen, modes[bestMode]);
        XF86VidModeSetViewPort(GLWin.dpy, GLWin.screen, 0, 0);
        dpyWidth = modes[bestMode]->hdisplay;
        dpyHeight = modes[bestMode]->vdisplay;
        printf("Resolution %dx%d\n", dpyWidth, dpyHeight);
        XFree(modes);
    
        /* create a fullscreen window */
        GLWin.attr.override_redirect = True;
        GLWin.attr.event_mask = ExposureMask | KeyPressMask | ButtonPressMask |
            StructureNotifyMask;
        GLWin.win = XCreateWindow(GLWin.dpy, RootWindow(GLWin.dpy, vi->screen),
            0, 0, dpyWidth, dpyHeight, 0, vi->depth, InputOutput, vi->visual,
            CWBorderPixel | CWColormap | CWEventMask | CWOverrideRedirect,
            &GLWin.attr);
        XWarpPointer(GLWin.dpy, None, GLWin.win, 0, 0, 0, 0, 0, 0);
		XMapRaised(GLWin.dpy, GLWin.win);
        XGrabKeyboard(GLWin.dpy, GLWin.win, True, GrabModeAsync,
            GrabModeAsync, CurrentTime);
        XGrabPointer(GLWin.dpy, GLWin.win, True, ButtonPressMask,
            GrabModeAsync, GrabModeAsync, GLWin.win, None, CurrentTime);
    }
    else
    {
        /* create a window in window mode*/
        GLWin.attr.event_mask = ExposureMask | KeyPressMask | ButtonPressMask |
            StructureNotifyMask;
        GLWin.win = XCreateWindow(GLWin.dpy, RootWindow(GLWin.dpy, vi->screen),
            0, 0, width, height, 0, vi->depth, InputOutput, vi->visual,
            CWBorderPixel | CWColormap | CWEventMask, &GLWin.attr);
        /* only set window title and handle wm_delete_events if in windowed mode */
        wmDelete = XInternAtom(GLWin.dpy, "WM_DELETE_WINDOW", True);
        XSetWMProtocols(GLWin.dpy, GLWin.win, &wmDelete, 1);
        XSetStandardProperties(GLWin.dpy, GLWin.win, title,
            title, None, NULL, 0, NULL);
        XMapRaised(GLWin.dpy, GLWin.win);
    }       
    /* connect the glx-context to the window */
    glXMakeCurrent(GLWin.dpy, GLWin.win, GLWin.ctx);
    XGetGeometry(GLWin.dpy, GLWin.win, &winDummy, &GLWin.x, &GLWin.y,
        &GLWin.width, &GLWin.height, &borderDummy, &GLWin.depth);
    printf("Depth %d\n", GLWin.depth);
    if (glXIsDirect(GLWin.dpy, GLWin.ctx)) 
        printf("Congrats, you have Direct Rendering!\n");
    else
        printf("Sorry, no Direct Rendering possible!\n");
    initGL();
    return True;    
}
/***********************************************************
***********************************************************
<<							>>
      <<		  MAIN 			>>
<<							>>
***********************************************************
***********************************************************/


int main(int argc, char **argv)
{ 
//>>>>>>>>>>>>>>>>>>>>>>START to Load PLY<<<<<<<<<<<<<<<<<<<
/*
// TODO find a way to allow to get multiple files from a directory

	if (argv[2] != NULL){
	
		int i;
		DIR * rep = opendir(argv[2]);
		if (rep != NULL)
		{
		struct dirent * ent;
		 
			while ((ent = readdir(rep)) != NULL)
			{
				printf("%s\n", ent->d_name);
			}
			closedir(rep);
		}

	}else 
		fprintf(stderr,"Error, precise the path to PLY ASCII files");
*/

	Trigidobject*	object ;

	printf(" File : %s \n", argv[1] ) ;

		int i=0;
		
		object = rigidobject_malloc() ;

		rigidobject_loadply( object, argv[1] ) ;
		Tpoint* compute_normals;
		
		for(i=0; i<object->nb_triangles; i++)
			compute_normals=Normal_Calcul(object, i);
		
	

	//rigidobject_print (object) ;

//>>>>>>>>>>>>>>>>>>>>>>END to Load PLY<<<<<<<<<<<<<<<<<<<

    XEvent event;
    Bool done;
    
   	
    done = False;
    /* default to fullscreen */
    GLWin.fs = False;
    createGLWindow("NeHe's Solid Objects Tutorial", 640, 480, 24, GLWin.fs);

    /* wait for events*/ 
    while (!done)
    {
        /* handle the events in the queue */
        while (XPending(GLWin.dpy) > 0)
        {
            XNextEvent(GLWin.dpy, &event);
            switch (event.type)
            {
                case Expose:
	                if (event.xexpose.count != 0)
	                    break;
                   	drawGLScene(compute_normals,object);
         	        	break;
	            case ConfigureNotify:
	            /* call resizeGLScene only if our window-size changed */
	                if ((event.xconfigure.width != GLWin.width) || 
	                    (event.xconfigure.height != GLWin.height))
	                {
	                    GLWin.width = event.xconfigure.width;
	                    GLWin.height = event.xconfigure.height;
                        printf("Resize event\n");
	                    resizeGLScene(event.xconfigure.width,
	                        event.xconfigure.height);
	                }
	                break;
                /* exit in case of a mouse button press */
                case ButtonPress:
                    done = False;
                    printf("Super Lapin!\n");
                    
                case KeyPress:
                    if (XLookupKeysym(&event.xkey, 0) == XK_Escape)
                    {
                        done = True;
                    }
                    if (XLookupKeysym(&event.xkey,0) == XK_F1)
                    {
                        killGLWindow();
                        GLWin.fs = !GLWin.fs;
                        createGLWindow("NeHe's Solid Objects Tutorial",
                            640, 480, 24, GLWin.fs);
                    }
                    if (XLookupKeysym(&event.xkey,0) == XK_F2){	
                        X+=0.0f;
                        Y+=0.0f;
                        Z+=0.01f;
                    	}
                    
                   	 if (XLookupKeysym(&event.xkey,0) == XK_F3){	
                        	 X+=0.0f;
                       		 Y+=0.0f;
                        	 Z-=0.01f;
                   	 }
                    
                        if (XLookupKeysym(&event.xkey,0) == XK_F4)     
				rotTri+=5.0f;
                    
                    break;
                case ClientMessage:
                    if (*XGetAtomName(GLWin.dpy, event.xclient.message_type) == 
                        *"WM_PROTOCOLS")
                    {
                        printf("Exiting sanely...\n");
                        done = True;
                    }
                    break;
                default:
                    break;
            }
        }
        drawGLScene(compute_normals, object);
	usleep(90000);
    }
    killGLWindow();
    exit (0);
	rigidobject_free ( object ) ;
}
