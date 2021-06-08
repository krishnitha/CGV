#include<gl/glut.h>
#include<math.h>
#include<stdio.h>

void draw_pixel(int x, int y) 
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void bla(int x1, int y1, int x2, int y2)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	if (dx < 0) 
		dx = -dx;
	if (dy < 0) 
		dy = -dy;
	incx = 1;
	if (x2 < x1) 
		incx = -1;
	incy = 1;
	if (y2 < y1) 
		incy = -1;
	x = x1; y = y1;
	if (dx > dy) 
	{
		draw_pixel(x, y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++) 
		{
			if (e >= 0) 
			{
				y += incy;
				e += inc1;
			}
			else
			{
				e += inc2;
			}
			x += incx;
			draw_pixel(x, y);
		}

	}
	else 
	{
		draw_pixel(x, y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++) 
		{
			if (e >= 0) 
			{
				x += incx;
				e += inc1;
			}
			else
			{
				e += inc2;
			}
			y += incy;
			draw_pixel(x, y);
		}
	}
}

void poly()
{
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	int n, x, y, x1, y1, x2, y2;
	printf("enter the value of n\n");
	scanf_s("%d", &n);
	if (n == 1)
	{
		printf("enter the point\n");
		scanf_s("%d%d", &x, &y);
		draw_pixel(x, y);
	}
	else
	{
		printf("enter the 1 point\n");
		scanf_s("%d%d", &x1, &y1);
		x = x1;
		y = y1;
		for (int i = 2; i <= n; i++)
		{
			printf("enter the %d point\n", i);
			scanf_s("%d%d", &x2, &y2);
			bla(x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
			if (i == n)
			{
				bla(x1, y1, x, y);
			}
		}
	}
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("polyline");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(poly);
	glutMainLoop();
}
