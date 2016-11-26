#pragma once

#include "individual.h"
#include "solvers.h"
#include <core/dataset.h>
#include <core/random.h>
#include <core/view.h>

namespace solvers {

    template <typename Genotype,
              typename Initializer,
              typename Mutator,
              typename Evaluator,
              typename Generator = default_random_generator>
    struct local_search : solver {
        template <typename Sseq>
        local_search(Genotype&& gen, Initializer&& ini, Mutator&& mut, Evaluator&& eva, Sseq&& seed)
            : solver(mut, eva, seq)
            , _solution(std::move(gen))
            , _neighbour(_solution)
            , _initializer(std::move(ini)){
            _initializer.apply(_solution.genotype, _generator);
        }

        double run(std::uint64_t generations) {
            for (std::uint64_t i = 0; i != generations; ++i)
                _step();
            return _solution.score;
        }

        double reevaluate(dataset const& a, dataset const& b) {
            evaluator().change_datasets(a, b);
            _solution.score = evaluator().apply(_solution.genotype);
            scores().emplace_back(_solution.score);
            return _solution.score;
        }

    private:
        individual<Genotype, double> _solution;
        individual<Genotype, double> _neighbour;

        Initializer _initializer;
        Generator _generator;

        void _step() {
            _neighbour = _solution;
            mutator().apply(_neighbour.genotype, _generator);

            _neighbour.score = evaluator().apply(_neighbour.genotype);
            if (_solution <= _neighbour) {
                _solution = std::move(_neighbour);
            }
            scores().emplace_back(_solution.score);
        }
    };

} // namespace solvers
