-- --------------------------------------------------------
-- 主机:                           127.0.0.1
-- 服务器版本:                        5.7.17-log - MySQL Community Server (GPL)
-- 服务器操作系统:                      Win64
-- HeidiSQL 版本:                  9.5.0.5196
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- 导出 tcc 的数据库结构
CREATE DATABASE IF NOT EXISTS `tcc` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `tcc`;

-- 导出  表 tcc.business_action 结构
CREATE TABLE IF NOT EXISTS `business_action` (
  `action_id` bigint(20) NOT NULL,
  `root_tx_id` bigint(20) NOT NULL COMMENT '根事务id',
  `tx_id` bigint(20) NOT NULL COMMENT '所在事务id',
  `service` varchar(54) NOT NULL COMMENT 'rpc暴露的服务名',
  `class` varchar(54) NOT NULL COMMENT '类',
  `action` varchar(54) NOT NULL COMMENT '方法',
  `context` varchar(500) DEFAULT NULL COMMENT '请求参数',
  `state` tinyint(4) NOT NULL DEFAULT '1' COMMENT '状态（TRYING(1), CONFIRMING(2), CANCELLING(3)）',
  `gmt_create` datetime DEFAULT CURRENT_TIMESTAMP,
  `gmt_modified` datetime DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`action_id`,`tx_id`,`root_tx_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='分支事务表';

-- 正在导出表  tcc.business_action 的数据：~0 rows (大约)
/*!40000 ALTER TABLE `business_action` DISABLE KEYS */;
INSERT INTO `business_action` (`action_id`, `root_tx_id`, `tx_id`, `service`, `class`, `action`, `context`, `state`, `gmt_create`, `gmt_modified`) VALUES
	(1, 1, 3, 'authService', 'cn.com.AuthService', 'auth', '["1111",{"action":"auth","actionId":1,"className":"cn.com.AuthService","rootTxId":1,"service":"authService","txId":3},78]', 2, '2018-05-14 11:24:28', '2018-05-14 11:24:53');
/*!40000 ALTER TABLE `business_action` ENABLE KEYS */;

-- 导出  表 tcc.business_activity 结构
CREATE TABLE IF NOT EXISTS `business_activity` (
  `tx_id` bigint(20) NOT NULL,
  `root_tx_id` bigint(20) DEFAULT NULL COMMENT '根事务id',
  `state` tinyint(4) NOT NULL DEFAULT '1' COMMENT '状态 TRYING(1), CONFIRMING(2), CANCELLING(3)',
  `par_tx_id` varchar(50) DEFAULT NULL COMMENT '父事务id',
  `gmt_create` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `gmt_modified` datetime DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`tx_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='主事务表';

-- 正在导出表  tcc.business_activity 的数据：~0 rows (大约)
/*!40000 ALTER TABLE `business_activity` DISABLE KEYS */;
INSERT INTO `business_activity` (`tx_id`, `root_tx_id`, `state`, `par_tx_id`, `gmt_create`, `gmt_modified`) VALUES
	(4, 4, 1, NULL, '2018-05-14 11:26:33', '2018-05-14 11:26:33');
/*!40000 ALTER TABLE `business_activity` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
