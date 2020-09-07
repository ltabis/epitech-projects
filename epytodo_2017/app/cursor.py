#!/usr/bin/python3
from flask import jsonify
from config import *
import pymysql as sql

def connect_to_server_and_get_cursor():
	try:
		connect = sql.connect(host=DATABASE_HOST,
		unix_socket=DATABASE_SOCK,
		user=DATABASE_USER,
		passwd=DATABASE_PASS,
		db=DATABASE_NAME)

		cursor = connect.cursor()
		return (cursor, connect)

	except Exception as e:
		print("Caught an exception :", e)

def close_connections(cursor, connect):
	cursor.close()
	connect.close()