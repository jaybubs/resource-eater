edit:
	vim justfile

# builds a static executable, and tags a docker image no optimisations needed
build:
	g++ resource-eater.cpp -lm -static -o eat
	docker build . -t resource-eater:latest

pack:
	docker save resource-eater:latest -o eat.tar

copy-to-cluster:
	sudo k0s ctr i import eat.tar

# if no external registry is used, the image can be loaded into a k0s cluster
k0s: pack && copy-to-cluster
