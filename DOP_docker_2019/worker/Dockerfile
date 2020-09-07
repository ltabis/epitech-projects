## STAGE 1

# Downloading maven image
FROM maven:3.5-jdk-8-alpine AS builder

# Copying the source files into the image
COPY files /files
WORKDIR /files

# Install dependencies
RUN mvn dependency:resolve && mvn package

## STAGE 2

# Downloading openjdk image
FROM openjdk:8-jre-alpine

# Copying the source files from the builder image into the current image
COPY --from=builder /files/target/worker-jar-with-dependencies.jar .

# Running the worker
CMD java -jar worker-jar-with-dependencies.jar
