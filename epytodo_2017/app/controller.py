#!/usr/bin/python3
from flask import render_template, request
from flask import jsonify
from app.models import *
import datetime

def render_main_page():
	return render_template("index.html",
	title="Main page")

def post_login_data(userlst, passlst):
	
	username = ""
	password = ""

	if request.method == 'POST' and len(userlst) == 0 and len(passlst) == 0:
		username = request.form['username']
		password = request.form['password']
		res = search_for_user(username, password)
		if res == 1:
			return render_template("loggedin.html",
		title="Main page", user=username), username, password
		else:
			return render_template("index.html",
		title="Main page"), "", ""
	else:
		return render_template("loggedin.html",
		title="Main page", user=userlst[0]), userlst[0], passlst[0]

def post_register_data():

	username = ""
	password = ""

	if request.method == 'POST':
		username = request.form['username']
		password = request.form['password']
	upload_user_to_database(username, password)
	return render_template("index.html",
	title="Main page")

def post_signout_data():
	return return_main_page()

def get_user_info(username):

	infos = get_infos(username)
	
	return render_template("user.html",
	title="User page", user=username[0],
	user_ID = infos[0], todo_list="nothing lol")

def show_all_user_tasks(username):
	
	infos = get_infos(username)
	tasks, nb_tasks = get_tasks_list(infos)

	if nb_tasks == 0:
		return render_template("tasks_none.html",
		title="Tasks page", user=username[0],
		task_lst="You don't have any tasks")
	else:
		return render_template("tasks.html",
		title="Tasks page", user=username[0],
		nb_tasks=nb_tasks, tasks=tasks)
	
def get_spec_task_infos(task_id, username):

	infos = get_task_infos(task_id)

	print(infos)
	return render_template("tasks_view.html",
	user=username[0],
	title="Task page", id=infos[0], name=infos[1],
	start=infos[2], stop=infos[3], status=infos[4])

def create_new_task(username):

	infos = get_infos(username)
	title = ""
	start = ""
	end = ""
	status = ""

	if request.method == 'POST':
		name = request.form['name']
		start = request.form['start']
		end = request.form['end']
		status = request.form['status']

	if start == "":
		start = datetime.datetime.now()
	if name == "":
		return render_template("tasks.html",
		title="Tasks page", user=username[0],
		nb_tasks=nb_tasks, tasks=tasks)
	updated_tasks(name, start, end, status, infos)
	tasks, nb_tasks = get_tasks_list(infos)
	return redirect("http://127.0.0.1:5000/user/task", code=302)