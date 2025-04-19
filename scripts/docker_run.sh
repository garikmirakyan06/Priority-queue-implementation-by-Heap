#!/bin/bash

image_name="pqueue_image"
container_name="pqueue_container"

cd .. || exit

sudo docker build -t $image_name .

if docker ps -a --format '{{.Names}}' | grep -w "$container_name" > /dev/null; then
    sudo docker stop $container_name
	sudo docker rm $container_name
fi

sudo docker run --name $container_name -it $image_name /bin/bash





