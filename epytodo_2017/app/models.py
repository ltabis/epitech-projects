#!/usr/bin/python3
from app.cursor import connect_to_server_and_get_cursor, close_connections
from flask import redirect

def search_for_user(username, password):
	
	result = ""
	i = 0

	data, connect = connect_to_server_and_get_cursor()
	data.execute("SELECT username, password from user")
	result = data.fetchall()
	for line in result:
		if username == result[i][0] and password == result[i][1]:
			return 1
		i += 1
	close_connections(data, connect)
	return 0

def upload_user_to_database(usr, passw):

	i = 0
	new_id = 0

	data, connect = connect_to_server_and_get_cursor()
	data.execute("SELECT * from user")
	lst = data.fetchall()
	for lines in lst:
		if lst[i][0] > new_id:
			new_id = int(lst[i][0])
		i += 1
	new_id += 1
	data.execute("INSERT INTO user (user_id,username,password) VALUES (%s,%s,%s)", (new_id,usr,passw));
	connect.commit();
	close_connections(data, connect)
	return 0

def return_main_page():
	return redirect("http://127.0.0.1:5000/", code=302)

def get_infos(username):

	infos = []
	i = 0

	data, connect = connect_to_server_and_get_cursor()
	data.execute("SELECT * from user")
	lst = data.fetchall()

	while i < len(lst) and i != -1:
		if username[0] == lst[i][1]:
			infos = lst[i]
			i = -2
		i += 1
	close_connections(data, connect)
	return infos

def get_tasks_list(infos):

	no_task = 1
	i = 0
	nb_tasks = 0
	tasks = []
	all_tasks = []

	data, connect = connect_to_server_and_get_cursor()
	data.execute("SELECT * from user_has_task")
	lst = data.fetchall()

	for line in lst:
		if infos[0] == lst[i][0]:
			tasks.append(lst[i][1])
			no_task = 0
		i += 1

	i = 0
	if no_task == 1:
		return all_tasks, 0
	data.execute("SELECT * from task")
	lst2 = data.fetchall()

	j = 0
	for line in lst2:
		if tasks[j] == int(lst2[i][0]):
			all_tasks.append(lst2[i])
			nb_tasks += 1
			j += 1
		i += 1

	close_connections(data, connect)
	return all_tasks, nb_tasks

def get_task_infos(task_id):

	lst = []
	i = 0

	data, connect = connect_to_server_and_get_cursor()
	data.execute("SELECT * from task")
	lst = data.fetchall()

	for line in lst:
		if task_id == str(lst[i][0]):
			close_connections(data, connect)
			return lst[i]
		i += 1

def updated_tasks(name, start, end, status, user):
	
	lst = []
	i = 0
	new_id = 0

	data, connect = connect_to_server_and_get_cursor()
	data.execute("SELECT * from task")
	lst = data.fetchall()

	for line in lst:
		if new_id <= int(lst[i][0]):
			new_id = int(lst[i][0]) + 1
		i += 1
	to_exec = "INSERT INTO task (task_id,title,begin,end,status) VALUES (%s,%s,%s,%s,%s)"
	data.execute(to_exec, (new_id,name,start,end,status))
	data.execute("INSERT INTO user_has_task (fk_user_id,fk_task_id) VALUES (%s,%s)", (user[0],new_id))
	connect.commit();
	close_connections(data, connect)

def delete_task(t_id):

	data, connect = connect_to_server_and_get_cursor()

	data.execute("DELETE FROM task WHERE task_id=%s", (t_id,))
	data.execute("DELETE FROM user_has_task WHERE fk_task_id=%s", (t_id,))
	connect.commit();
	close_connections(data, connect)