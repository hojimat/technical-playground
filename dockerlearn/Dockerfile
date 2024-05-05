FROM python
WORKDIR /mnt/code
COPY requirements.txt /mnt/code/requirements.txt
RUN apt-get update && apt-get install -y vim netcat && pip install -r requirements.txt
COPY . /mnt/code

