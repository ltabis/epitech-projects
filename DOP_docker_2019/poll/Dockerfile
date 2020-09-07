# Downloading python image with the last version
FROM python:3.7.5

# Copying the source files into the image
COPY files files
WORKDIR files

# Install dependencies
RUN pip install -r requirements.txt

# Listen on port 80
EXPOSE 80

# Launch the app
CMD flask run --host=0.0.0.0 --port=80
