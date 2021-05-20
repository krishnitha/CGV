#include<gl/glut.h>
#include<math.h>
#include<stdio.h>

void dda(int x1, int y1, int x2, int y2)
{
	int steps;
	int dx = x2 - x1;
	int dy = y2 - y1;
	if (abs(dx) > abs(dy)) {
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}
	float xInc = (float)dx / (float)steps;
	float yInc = (float)dy / (float)steps;
	float x = x1, y = y1;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	for (int i = 0; i < steps; i++) {
		x += xInc;
		y += yInc;
		glVertex2i(round(x), round(y));
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
		glBegin(GL_POINTS);
		glVertex2i(x, y);
	}
	else
	{
		printf("enter the 1 point\n");
		scanf_s("%d%d", &x, &y);
		x1 = x;
		y1 = y;
		for (int i = 2; i <= n; i++)
		{
			printf("enter the %d point\n",i);
			scanf_s("%d%d", &x2, &y2);
			dda(x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
			if (i == n)
			{
				dda(x1, y1, x, y);
			}
		}
	}
	glEnd();
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("polyline");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(poly);
	glutMainLoop();
}
