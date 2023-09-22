SFML_LIBS = -L include\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-main -mwindows
SFML_INCLUDE = -I include\SFML\include

Vectors : build\main.o build\common.o build\coord_system.o build\vectors.o
	g++ $(SFML_LIBS) build\main.o build\common.o build\coord_system.o build\vectors.o -o Vectors.exe -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-main -mwindows

build\main.o : source\main.cpp
	g++ $(SFML_INCLUDE) -c source\main.cpp -o build\main.o -D SFML_STATIC

build\common.o : source\common.cpp
	g++ $(SFML_INCLUDE) -c source\common.cpp -o build\common.o -D SFML_STATIC

build\coord_system.o : source\coord_system.cpp
	g++ $(SFML_INCLUDE) -c source\coord_system.cpp -o build\coord_system.o -D SFML_STATIC

build\vectors.o : source\vectors.cpp
	g++ $(SFML_INCLUDE) -c source\vectors.cpp -o build\vectors.o -D SFML_STATIC

.PHONY : clean

clean : 
	if exist Vectors.exe del Vectors.exe
	del /q .\build