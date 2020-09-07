#!/usr/bin/python3
from app import app
from app.controller import *

username = []
password = []

@app.route('/', methods = ['GET'])
def route_main_menu():
	result = render_main_page()
	return result

@app.route('/register', methods = ['POST'])
def route_post_user():
	registered = post_register_data()
	return registered

@app.route('/signin', methods = ['POST'])
def route_post_signin():
	loged, user, passw = post_login_data(username, password)
	username.clear()
	username.append(user)
	password.clear()
	password.append(passw)
	return loged

@app.route('/signout', methods = ['POST'])
def route_signout():
	out = post_signout_data()
	username.clear()
	password.clear()
	return out

@app.route('/user', methods = ['GET'])
def route_user():
	infos = get_user_info(username)
	return infos

@app.route('/user/task', methods = ['GET'])
def route_user_task():
	disp_tasks = show_all_user_tasks(username)
	return disp_tasks

@app.route('/user/task/<task_id>', methods = ['GET'])
def route_user_task_id(task_id):
	disp_task = get_spec_task_infos(task_id, username)
	return disp_task

@app.route('/user/task/<task_id>', methods = ['POST'])
def route_user_task_id_loged():
	disp_task = get_spec_task_infos(task_id, username)
	return disp_task

@app.route('/user/task/add', methods = ['POST'])
def route_ser_task_add():
	new_task = create_new_task(username)
	return new_task

@app.route('/user/task/del/<task_id>', methods = ['POST'])
def route_ser_task_del(task_id):
	del_task = delete_task_by_id(task_id, username)
	return del_task

@app.route('/about', methods = ['GET'])
def route_get_about():
	return render_template("about.html",
	title="about page")

@app.route('/useless', methods = ['GET'])
def route_get_useless():
        return render_template("useless.html",
    	title="about page")

@app.route('/agenda', methods = ['GET'])
def route_get_agenda():
        return render_template("agenda.html",
    	title="about page")