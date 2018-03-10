CREATE TABLE prons (
    words_id INT,
    type ENUM('British','American','Other') NOT NULL,
    pron VARCHAR(100) NOT NULL,
    FOREIGN KEY (words_id) REFERENCES words(id)
        ON DELETE CASCADE
) ENGINE=INNODB;

CREATE TABLE words(
    id int NOT NULL auto_increment,
    word varchar(100) NOT NULL,
    source varchar(100),
    PRIMARY KEY (id)
) ENGINE=INNODB;


CREATE TABLE defs (
    words_id INT,
    type VARCHAR(20),
    def TEXT NOT NULL,
    FOREIGN KEY (words_id) REFERENCES words(id)
        ON DELETE CASCADE
) ENGINE=INNODB;