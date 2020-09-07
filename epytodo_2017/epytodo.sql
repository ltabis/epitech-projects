CREATE DATABASE epytodo;

CREATE TABLE epytodo.user(
        user_id int,
        username varchar(255),
        password varchar(255)
);

CREATE TABLE epytodo.task(
        task_id int,
        title varchar(255),
        begin int,
        end int,
        status varchar(255)
);

CREATE TABLE epytodo.user_has_task(
        fk_user_id int,
        fk_task_id int
);