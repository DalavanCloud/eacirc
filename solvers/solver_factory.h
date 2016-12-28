#pragma once

#include "solvers.h"

#include "local_search.h"
#include "simulated_annealing.h"

#include "../eacirc/circuit/backend.h"
#include "../eacirc/circuit/circuit.h"
#include "../eacirc/circuit/genetics.h"

#include <core/memory.h>
#include <core/random.h>

namespace solvers {

    template <typename Circuit, typename Sseq>
    std::unique_ptr<solver> create_solver(unsigned tv_size, const json& config, Sseq& seed) {
        using ini = circuit::basic_initializer;
        using mut = circuit::basic_mutator;
        using eva = circuit::categories_evaluator<Circuit>;

        circuit::fn_set function_set(config.at("function-set"));

        const json solver = config.at("solver");

        std::string sol_type = solver.at("internal");

        if (sol_type == "local-search") {
            return std::make_unique<local_search<Circuit, ini, mut, eva>>(
                    Circuit(tv_size),
                    ini(config.at("initializer"), function_set),
                    mut(config.at("mutator"), function_set),
                    eva(config.at("evaluator")),
                    seed);
        }
        if (sol_type == "simulated-annealing") {
            return std::make_unique<simulated_annealing<Circuit, ini, mut, eva>>(
                    Circuit(tv_size),
                    ini(config.at("initializer"), function_set),
                    mut(config.at("mutator"), function_set),
                    eva(config.at("evaluator")),
                    seed,
                    float(solver.at("initial-temperature")),
                    float(solver.at("cooling-ratio")));
        } else
            throw std::runtime_error("no such solver named [" + sol_type + "] is avalable");
    }

} // namespace solvers
