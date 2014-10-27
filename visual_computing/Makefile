.PHONY install apt-install

install:
	source venv/bin/activate
	pip install -r requirements.txt

apt-install:
	sudo apt-get install libblas-dev
	sudo apt-get install liblapack-dev
	sudo apt-get install gfortran
	make install