package br.com.icarros.testes.api.controller;


import br.com.icarros.testes.api.service.ResultService;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api/v1/results")
public class ResultController {
    private final ResultService service;

    public ResultController(ResultService service) {
        this.service = service;
    }
    @GetMapping
    public feign.Response getAll() {
        return service.getAllResults();
    }
}
