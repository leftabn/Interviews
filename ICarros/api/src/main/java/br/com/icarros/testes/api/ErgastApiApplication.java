package br.com.icarros.testes.api;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;

@SpringBootApplication
@EnableFeignClients
public class ErgastApiApplication {

	public static void main(String[] args) {
		SpringApplication.run(ErgastApiApplication.class, args);
	}

}
