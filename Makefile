my_app: main.c
	clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraylib.a main.c -o my_app
	./my_app

run:
	./my_app

clean:
	rm -rf my_app