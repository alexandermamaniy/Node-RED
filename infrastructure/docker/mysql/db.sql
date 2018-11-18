
use temperature;

DROP TABLE IF EXISTS `data`;

CREATE TABLE `data` (
      id  int NOT NULL AUTO_INCREMENT,
      date datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
      temperature int,
      PRIMARY KEY(`id`)
);

INSERT INTO data(temperature) VALUES (30), (45);

SELECT * from data ;