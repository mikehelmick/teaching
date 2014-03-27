create table categories (
	id int not null primary key auto_increment,
	name varchar(50) not null,
	unique index name_idx( name )
) type = InnoDB;

create table products (
	id int not null primary key auto_increment,
	category_id int not null,
	name varchar(50) not null,
	price int not null,
	unique index products_name_idx( name ),
	foreign key(category_id) references categories(id)
) type = InnoDB;

# insert categories
insert into categories (id, name) values( 0, 'Comedy');
insert into categories (id, name) values( 0, 'TV');
	
insert into products (id,category_id,name,price) 
	values ( 0, 1, 'Dodgeball', 1395 );
insert into products (id,category_id,name,price) 
	values ( 0, 1, 'Zoolander', 995 );
insert into products (id,category_id,name,price) 
	values ( 0, 2, 'Scrubs (Season 1)', 1495 );
insert into products (id,category_id,name,price) 
	values ( 0, 2, 'Scrubs (Season 2)', 1995 );
	
	
	