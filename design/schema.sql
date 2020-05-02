// TO DISTINGUISH BETWEEN ADMIN OR NORMAL USER
CREATE TABLE IF NOT EXISTS usertype(
	type varchar(20) PRIMARY KEY
	);

CREATE TABLE IF NOT EXISTS user(

	uname text(20) PRIMARY KEY,
	upassword varchar(50),
	usertype varchar(20) ,// for admin and normal user
	CONSTRAINT fk_usertype FOREIGN KEY (usertype) REFERENCES usertype(type)
);

CREATE TABLE IF NOT EXISTS group(
	groupid int AUTO_INCREMENT PRIMARY KEY,
	groupname text(20),
	groupdiscription text(50),
	groupcreateddate datetime,
);

CREATE TABLE IF NOT EXISTS user_group(
	uname text(20),
	groupid int,
	CONSTRAINT fk_user_group FOREIGN KEY (uname,groupid) REFERENCES user,group

);

// resource is file and folder that we are creating
//  in here parent is the paernt folder in that we are creating file or folder
CREATE TABLE IF NOT EXISTS resource(
	rid int AUTO_INCREMENT PRIMARY KEY,
	rname varchar(20),
	rtype text(20),
	parent int
 CONSTRAINT fk_user_resource FOREIGN KEY (parent) REFERENCES resource(rid)
);


CREATE TABLE IF NOT EXISTS permission(
	ptype text(20) PRIMARY KEY
);

CREATE TABLE IF NOT EXISTS group_permission(
	groupid int,
	rid int,
	ptype text(20),
CONSTRAINT fk_group_permission FOREIGN KEY (groupid,rid,ptype) REFERENCES group,resource,permission
);

CREATE TABLE IF NOT EXISTS user_permission(
	username text(20),
	rid int,
	ptype text(20),
	CONSTRAINT fk_user_permission FOREIGN KEY (uname,rid,ptype) REFERENCES user,resource,permission

);

