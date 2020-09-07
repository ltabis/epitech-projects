# Downloading python image with the last version
FROM node:latest

# Copying the source files into the image / set work directory to the src folder
COPY files files
WORKDIR files

# Install dependencies
RUN npm install

# Listen on port 80
EXPOSE 80

# Command to launch 
CMD node server.js
