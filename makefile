grafica.pdf:datos.txt
	python grafica.py
	rm datos.txt
datos.txt:difusion.x
	./difusion.x > datos.txt
	rm difusion.x
difusion.x:
	c++ difusion.cpp -o difusion.x
clean:
	rm *.pdf
