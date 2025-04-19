FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
		g++ \
		cmake \
		make \
		curl \
		wget \ 
		vim

WORKDIR /app
		
COPY . . 

RUN /app/scripts/build.sh

CMD ["/app/bin/PQueue"]


